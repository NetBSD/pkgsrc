# $NetBSD: Makefile,v 1.32 2000/03/30 13:01:49 hubertf Exp $
# FreeBSD Id: Makefile,v 1.35 1997/08/19 07:10:01 fenner Exp
#

.include "mk/bsd.prefs.mk"

.ifdef SPECIFIC_PKGS
SUBDIR+=	${SITE_SPECIFIC_PKGS}
SUBDIR+=	${HOST_SPECIFIC_PKGS}
SUBDIR+=	${GROUP_SPECIFIC_PKGS}
SUBDIR+=	${USER_SPECIFIC_PKGS}
.else
SUBDIR += archivers
SUBDIR += audio
SUBDIR += benchmarks
SUBDIR += biology
SUBDIR += cad
SUBDIR += comms
SUBDIR += converters
SUBDIR += corba
SUBDIR += cross
SUBDIR += databases
SUBDIR += devel
SUBDIR += editors
SUBDIR += emulators
SUBDIR += games
SUBDIR += graphics
SUBDIR += ham
SUBDIR += japanese
SUBDIR += lang
SUBDIR += mail
SUBDIR += math
SUBDIR += mbone
SUBDIR += meta-pkgs
SUBDIR += misc
SUBDIR += net
SUBDIR += news
SUBDIR += parallel
SUBDIR += pkgtools
SUBDIR += plan9
SUBDIR += print
SUBDIR += security
SUBDIR += shells
SUBDIR += sysutils
SUBDIR += textproc
SUBDIR += www
SUBDIR += x11
.endif

PKGSRCTOP=	yes

.include "mk/bsd.pkg.subdir.mk"

index:
	@rm -f ${.CURDIR}/INDEX
	@${MAKE} ${.CURDIR}/INDEX

${.CURDIR}/INDEX:
	@echo -n "Generating INDEX - please wait.."
	@${MAKE} describe ECHO_MSG="echo > /dev/null" > ${.CURDIR}/INDEX
	@echo " Done."

print-index:	${.CURDIR}/INDEX
	@awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\nArch:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9, $$10); }' < ${.CURDIR}/INDEX

search:	${.CURDIR}/INDEX
.if !defined(key)
	@echo "The search target requires a keyword parameter,"
	@echo "e.g.: \"${MAKE} search key=somekeyword\""
.else
	@grep ${key} ${.CURDIR}/INDEX | awk -F\| '{ printf("Port:\t%s\nPath:\t%s\nInfo:\t%s\nMaint:\t%s\nIndex:\t%s\nB-deps:\t%s\nR-deps:\t%s\nArch:\t%s\n\n", $$1, $$2, $$4, $$6, $$7, $$8, $$9, $$10); }'
.endif


# 
# Generate list of all packages by extracting information from
# the category/README.html pages
#
readme-all:
	@if [ -f README-all.html ]; then \
		mv README-all.html README-all.html.BAK ; \
	fi
	@${MAKE} README-all.html
	@if cmp -s README-all.html README-all.html.BAK  ; then \
		mv README-all.html.BAK README-all.html ; \
	else \
		rm -f README-all.html.BAK ; \
	fi

README-all.html:
	@rm -f $@.new
	@rm -f $@.newsorted
	@echo -n "Processing categories for $@:"
.for category in ${SUBDIR}
	@if [ -f ${category}/README.html ]; then \
		echo -n ' ${category}' ; \
		grep '^<TR>' ${category}/README.html \
		| sed -e 's|"|"${category}/|' \
		      -e 's| <TD>| <TD>(<A HREF="${category}/README.html">${category}</A>) <TD>|' \
		      -e 's|<TR>|<TR VALIGN=TOP>|' \
		      -e 's|<TD VALIGN=TOP>|<TD>|' \
		>> $@.new ; \
	fi
.endfor
	@echo "."
	@sort -f -t '">' +2 <$@.new >$@.newsorted
	@wc -l $@.newsorted | awk '{ print $$1 }'  >$@.npkgs
	@cat templates/README.all \
	| ${SED} \
                -e '/%%NPKGS%%/r$@.npkgs' \
                -e '/%%NPKGS%%/d' \
                -e '/%%PKGS%%/r$@.newsorted' \
                -e '/%%PKGS%%/d' \
        	> $@ 
	@rm -f $@.npkgs
	@rm -f $@.new
	@rm -f $@.newsorted



readme-ipv6:
	@if [ -f README-IPv6.html ]; then \
		mv README-IPv6.html README-IPv6.html.BAK ; \
	fi
	@${MAKE} README-IPv6.html
	@if cmp -s README-IPv6.html README-IPv6.html.BAK  ; then \
		mv README-IPv6.html.BAK README-IPv6.html ; \
	else \
		rm -f README-IPv6.html.BAK ; \
	fi

README-IPv6.html:
	@grep -l '^BUILD_DEFS.*=.*USE_INET6' */*/Makefile \
	 | sed s,.Makefile,, >$@.pkgs
	@fgrep -f $@.pkgs README-all.html | sort -t/ +1 >$@.trs
	@cat templates/README.ipv6 \
	| ${SED} \
                -e '/%%TRS%%/r$@.trs' \
                -e '/%%TRS%%/d' \
		>$@
	@${RM} $@.trs
	@${RM} $@.pkgs
