#	$NetBSD: bsd.pkg.subdir.mk,v 1.20 1998/07/26 03:25:54 lukem Exp $
#	Derived from: FreeBSD Id: bsd.port.subdir.mk,v 1.19 1997/03/09 23:10:56 wosch Exp 
#	from: @(#)bsd.subdir.mk	5.9 (Berkeley) 2/1/91
#
# The include file <bsd.pkg.subdir.mk> contains the default targets
# for building ports subdirectories. 
#
#
# +++ variables +++
#
# STRIPFLAG	The flag passed to the install program to cause the binary
#		to be stripped.  This is to be used when building your
#		own install script so that the entire system can be made
#		stripped/not-stripped using a single knob. [-s]
#
# ECHO_MSG	Used to print all the '===>' style prompts - override this
#		to turn them off [echo].
#
# OPSYS		Get the operating system type [`uname -s`]
#
# SUBDIR	A list of subdirectories that should be built as well.
#		Each of the targets will execute the same target in the
#		subdirectories.
#
#
# +++ targets +++
#
#	README.html:
#		Creating README.html for package.
#
#	afterinstall, all, beforeinstall, build, checksum, clean,
#	configure, deinstall, depend, describe, extract, fetch, fetch-list, 
#	install, package, readmes, realinstall, reinstall, tags,
#	mirror-distfiles
#


.MAIN: all

.if !defined(DEBUG_FLAGS)
STRIPFLAG?=	-s
.endif

.if !defined(OPSYS)	# XXX !!
OPSYS!=	uname -s
.endif

ECHO_MSG?=	echo

_SUBDIRUSE: .USE
	@for entry in ${SUBDIR}; do \
		OK=""; \
		for dud in $$DUDS; do \
			if [ $${dud} = $${entry} ]; then \
				OK="false"; \
				${ECHO_MSG} "===> ${_THISDIR_}$${entry} skipped"; \
			fi; \
		done; \
		if test -d ${.CURDIR}/$${entry}.${MACHINE}; then \
			edir=$${entry}.${MACHINE}; \
		elif test -d ${.CURDIR}/$${entry}; then \
			edir=$${entry}; \
		else \
			OK="false"; \
			${ECHO_MSG} "===> ${_THISDIR_}$${entry} non-existent"; \
		fi; \
		if [ "$$OK" = "" ]; then \
			cd ${.CURDIR}/$${edir}; \
			if [ -z "${_THISDIR_}" -a ! -d "files" ]; then \
				${ECHO_MSG} "===> category ${_THISDIR_}$${edir}"; \
				${MAKE} ${.TARGET:realinstall=install} \
					"_THISDIR_=${_THISDIR_}$${edir}/"; \
			else \
				${ECHO_MSG} "===> package ${_THISDIR_}$${edir}"; \
				${MAKE} ${.TARGET:realinstall=install} \
					"_THISDIR_=${_THISDIR_}$${edir}/" || /usr/bin/true ; \
			fi ; \
		fi; \
	done

${SUBDIR}::
	@if test -d ${.TARGET}.${MACHINE}; then \
		cd ${.CURDIR}/${.TARGET}.${MACHINE}; \
	else \
		cd ${.CURDIR}/${.TARGET}; \
	fi; \
	${MAKE} all

.for __target in all fetch fetch-list package extract configure \
		 build clean distclean depend describe reinstall tags checksum \
		 mirror-distfiles deinstall
.if !target(__target)
${__target}: _SUBDIRUSE
.endif
.endfor

.if !target(install)
.if !target(beforeinstall)
beforeinstall:
.endif
.if !target(afterinstall)
afterinstall:
.endif
install: afterinstall
afterinstall: realinstall
realinstall: beforeinstall _SUBDIRUSE
.endif

.if !target(readmes)
readmes: readme _SUBDIRUSE
.endif

.if !target(readme)
readme:
	@if [ -f README.html ]; then  mv -f README.html README.html.BAK ; fi
	@${MAKE} README.html
.endif

.if defined(PKGSRCTOP)
README=	templates/README.top
.else
README=	../templates/README.category
.endif

HTMLIFY=	sed -e 's/&/\&amp;/g' -e 's/>/\&gt;/g' -e 's/</\&lt;/g'

README.html: .PRECIOUS
	@> $@.tmp
.for entry in ${SUBDIR}
.if defined(PKGSRCTOP)
	@echo -n '<TR><TD VALIGN=TOP><a href="'${entry}/README.html'">'"`echo ${entry} | ${HTMLIFY}`"'</a>: <TD>' >> $@.tmp
.else
	@echo -n '<TR><TD VALIGN=TOP><a href="'${entry}/README.html'">'"`cd ${entry}; ${MAKE} package-name | ${HTMLIFY}`</a>: <TD>" >> $@.tmp
.endif
.if exists(${entry}/pkg/COMMENT)
	@${HTMLIFY} ${entry}/pkg/COMMENT >> $@.tmp
.else
	@echo "(no description)" >> $@.tmp
.endif
.endfor
	@sort -t '>' +3 -4 $@.tmp > $@.tmp2
.if exists(${.CURDIR}/pkg/DESCR)
	@${HTMLIFY} ${.CURDIR}/pkg/DESCR > $@.tmp3
.else
	@> $@.tmp3
.endif
	@cat ${README} | \
		sed -e 's/%%CATEGORY%%/'"`basename ${.CURDIR}`"'/g' \
			-e '/%%DESCR%%/r$@.tmp3' \
			-e '/%%DESCR%%/d' \
			-e '/%%SUBDIR%%/r$@.tmp2' \
			-e '/%%SUBDIR%%/d' \
		> $@.tmp4
	@if cmp -s $@.tmp4 $@.BAK ; then \
		mv $@.BAK $@ ; \
		rm $@.tmp4 ; \
	else \
		${ECHO_MSG} "===>  Creating README.html for ${_THISDIR_}${.CURDIR:T}" ; \
		mv $@.tmp4 $@ ; \
		rm -f $@.BAK ; \
	fi
	@rm -f $@.tmp $@.tmp2 $@.tmp3
.for subdir in ${SUBDIR}
	@cd ${subdir} && ${MAKE} "_THISDIR_=${_THISDIR_}${.CURDIR:T}/" readme
.endfor
