# $NetBSD: toplevel.mk,v 1.7 2016/07/11 22:53:48 wiz Exp $
#
# This file contains the make targets that can be used from the
# top-level Makefile. They are in this separate file to keep the
# top-level file short and clean.
#
#

# If PACKAGES is set to the default (${PKGSRCDIR}/packages), the current
# ${MACHINE_ARCH} and "release" (uname -r) will be used. Otherwise a directory
# structure of ...pkgsrc/packages/`uname -r`/${MACHINE_ARCH} is assumed.
# The PKG_URL is set from FTP_PKG_URL_* or CDROM_PKG_URL_*, depending on
# the target used to generate the README.html file.
.PHONY: README.html
_README_TYPE_FLAG?=	none
README.html: .PRECIOUS
.if ${_README_TYPE_FLAG} == "--ftp" || ${_README_TYPE_FLAG} == "--cdrom"
	${PKGSRC_SETENV} TMPDIR=${TMPDIR:U/tmp}/mkreadme	 		\
		BMAKE=${MAKE}						\
		./mk/scripts/mkreadme --pkgsrc ${.CURDIR} 		\
		--packages ${PACKAGES} ${_README_TYPE_FLAG}		\
		--prune --quiet
.else
	@${ECHO} "ERROR:  please do not use the README.html target directly."
	@${ECHO} "        Instead use either the \"readme\" or \"cdrom-readme\""
	@${ECHO} "        target."
	@${FALSE}
.endif

.include "../bsd.pkg.subdir.mk"

.PHONY: ${.CURDIR}/PKGDB
${.CURDIR}/PKGDB:
	@${RM} -f ${.CURDIR}/PKGDB
	@${ECHO_MSG} "Extracting complete dependency database.  This may take a while..."
	@DB=${.CURDIR}/PKGDB ; \
	PKGSRCDIR=${.CURDIR} ; \
	npkg=1; \
	list=`${GREP} '^[[:space:]]*'SUBDIR */Makefile | ${SED} 's,/Makefile.*=[[:space:]]*,/,'` ; \
	for pkgdir in $$list ; do \
		if [ ! -d $$pkgdir ]; then  \
			echo " " ; \
			echo "WARNING:  the package directory $$pkgdir is listed in" > /dev/stderr ; \
			echo $$pkgdir | ${SED} 's;/.*;/Makefile;g' > /dev/stderr ; \
			echo "but the directory does not exist.  Please fix this!" > /dev/stderr ; \
		else \
			cd $$pkgdir ; \
			l=`${MAKE} print-summary-data`  ; \
			if [ $$? != 0 ]; then \
				echo "WARNING (printdepends):  the package in $$pkgdir had problem with" \
					> /dev/stderr ; \
				echo "    ${MAKE} print-summary-data" > /dev/stderr ; \
				echo "    database information for this package" > /dev/stderr ; \
				echo "    will be dropped." > /dev/stderr ; \
				${MAKE} print-summary-data  2>&1 > /dev/stderr ; \
			else \
				echo "$$l" >> $$DB ; \
			fi ; \
		fi ; \
		${ECHO_N} "."; \
		if [ `${EXPR} $$npkg % 100 = 0` -eq 1 ]; then \
			echo " " ; \
			echo "$$npkg" ; \
		fi ; \
		npkg=`${EXPR} $$npkg + 1` ; \
		cd $$PKGSRCDIR  ; \
	done

.PHONY: index
index:
	@${RM} -f ${.CURDIR}/INDEX
	@${MAKE} ${.CURDIR}/INDEX

${.CURDIR}/INDEX:
	@${MAKE} ${.CURDIR}/PKGDB
	@${RM} -f ${.CURDIR}/INDEX
	@${AWK} -f ./mk/scripts/genindex.awk PKGSRCDIR=${.CURDIR} SORT=${SORT} ${.CURDIR}/PKGDB
	@${RM} -f ${.CURDIR}/PKGDB

print-index: ${.CURDIR}/INDEX
	@${AWK} -F\| '{ printf("Pkg:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\nArch:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9, $$10); }' < ${.CURDIR}/INDEX

search: ${.CURDIR}/INDEX
.if !defined(key)
	@${ECHO} "The search target requires a keyword parameter,"
	@${ECHO} "e.g.: \"${MAKE} search key=somekeyword\""
.else
	@${GREP} ${key} ${.CURDIR}/INDEX | ${AWK} -F\| '{ printf("Pkg:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\nArch:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9, $$10); }'
.endif

#
# Generate list of all packages by extracting information from
# the category/README.html pages
#
readme-all:
	@if [ -f README-all.html ]; then \
		${MV} README-all.html README-all.html.BAK ; \
	fi
	@${MAKE} README-all.html
	@if ${CMP} -s README-all.html README-all.html.BAK ; then \
		${MV} README-all.html.BAK README-all.html ; \
	else \
		${RM} -f README-all.html.BAK ; \
	fi

README-all.html:
	@${RM} -f $@.new
	@${RM} -f $@.newsorted
	@${ECHO_N} "Processing categories for $@:"
.for category in ${SUBDIR}
	@if [ -f ${category}/README.html ]; then \
		${ECHO_N} ' ${category}' ; \
		${GREP} '^<TR>' ${category}/README.html \
		| ${SED} -e 's|"|"${category}/|' \
		      -e 's| <TD>| <TD>(<A HREF="${category}/README.html">${category}</A>) <TD>|' \
		      -e 's|<TR>|<TR VALIGN=TOP>|' \
		      -e 's|<TD VALIGN=TOP>|<TD>|' \
		>> $@.new ; \
	fi
.endfor
	@${ECHO} "."
	@if [ ! -f $@.new ]; then \
		${ECHO} "There are no categories with README.html files available."; \
		${ECHO} "You need to run \`${MAKE} readme' to generate them before running this target."; \
		${FALSE}; \
	fi
	@${SORT} -f -t '">' +2 <$@.new >$@.newsorted
	@${WC} -l $@.newsorted | ${AWK} '{ print $$1 }'  >$@.npkgs
	@${CAT} templates/README.all \
	| ${SED} \
		-e '/%%NPKGS%%/r$@.npkgs' \
		-e '/%%NPKGS%%/d' \
		-e '/%%PKGS%%/r$@.newsorted' \
		-e '/%%PKGS%%/d' \
		> $@
	@${RM} -f $@.npkgs
	@${RM} -f $@.new
	@${RM} -f $@.newsorted

readme-ipv6:
	@if [ -f README-IPv6.html ]; then \
		${MV} README-IPv6.html README-IPv6.html.BAK ; \
	fi
	@${MAKE} README-IPv6.html
	@if ${CMP} -s README-IPv6.html README-IPv6.html.BAK  ; then \
		${MV} README-IPv6.html.BAK README-IPv6.html ; \
	else \
		${RM} -f README-IPv6.html.BAK ; \
	fi

README-IPv6.html:
	@${GREP} -l -e '^BUILD_DEFS.*=.*IPV6_READY' -e '^PKG_SUPPORTED_OPTIONS.*=.*inet6' -e '^USE_FEATURES.*=.*inet6' \
		 */*/Makefile */*/options.mk \
	 | ${SED} -e s,Makefile,, -e s,options.mk,, >$@.pkgs
	@${FGREP} -f $@.pkgs README-all.html | ${SORT} -t/ +1 >$@.trs
	@${CAT} templates/README.ipv6 \
	| ${SED} \
		-e '/%%TRS%%/r$@.trs' \
		-e '/%%TRS%%/d' \
		>$@
	@${RM} $@.pkgs $@.trs

show-host-specific-pkgs:
	@${ECHO} "HOST_SPECIFIC_PKGS= \\";					\
	${MAKE} show-pkgsrc-dir | ${AWK} '/^===/ { next; } { printf("%s \\\n", $$1) }'; \
	${ECHO} ""

# list all packages that depend on a particular package; needs the INDEX file
# usage: 'make show-deps PKG=openssl'
# PKG: name of the package
show-deps:
	@if [ ! -f "${.CURDIR}/INDEX" ]; then ${ECHO} "No index available -- please build it with 'make index'" >&2; ${FALSE}; fi
	@if [ -z "${PKG}" ]; then ${ECHO} "PKG variable not set" >&2; ${FALSE}; fi
	@${GREP} -E "^([^|]*\|){7}([^|]* |)${PKG}>=" ${.CURDIR}/INDEX | ${SED} -n 's/^[^|]*|\([^|]*\)|.*/\1/p' | ${SORT}
