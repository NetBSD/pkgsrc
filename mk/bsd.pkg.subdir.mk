#	$NetBSD: bsd.pkg.subdir.mk,v 1.71 2020/06/05 17:05:22 rillig Exp $
#	Derived from: FreeBSD Id: bsd.port.subdir.mk,v 1.19 1997/03/09 23:10:56 wosch Exp
#	from: @(#)bsd.subdir.mk	5.9 (Berkeley) 2/1/91
#
# The include file <bsd.pkg.subdir.mk> contains the default targets
# for building ports subdirectories.
#
#
# +++ variables +++
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
#	mirror-distfiles, ${PKG_MISC_TARGETS}
#

.include "misc/common.mk"

AWK?=		/usr/bin/awk
CAT?=		/bin/cat
BASENAME?=	/usr/bin/basename
ECHO?=		echo
ECHO_MSG?=	${ECHO}
MV?=		/bin/mv
RM?=		/bin/rm
SED?=		/usr/bin/sed
SORT?=		/usr/bin/sort

_SUBDIRUSE: .USE
	@for entry in "" ${SUBDIR}; do \
		if [ "X$$entry" = "X" ]; then continue; fi; \
		OK=""; \
		for dud in "" ${DUDS}; do \
			if [ "X$$dud" = "X" ]; then continue; fi; \
			if [ $${dud} = $${entry} ]; then \
				OK="false"; \
				${ECHO_MSG} "===> ${_THISDIR_}$${entry} skipped"; \
			fi; \
		done; \
		if [ -d ${.CURDIR}/$${entry}.${MACHINE} ]; then \
			edir=$${entry}.${MACHINE}; \
		elif [ -d ${.CURDIR}/$${entry} ]; then \
			edir=$${entry}; \
		else \
			OK="false"; \
			${ECHO_MSG} "===> ${_THISDIR_}$${entry} non-existent"; \
		fi; \
		if [ "$$OK" = "" ]; then \
			cd ${.CURDIR}/$${edir}; \
			${ECHO_MSG} "===> ${_THISDIR_}$${edir}"; \
			${RECURSIVE_MAKE} ${MAKEFLAGS} "_THISDIR_=${_THISDIR_}$${edir}/" \
			    ${.TARGET:realinstall=install} || true; \
		fi; \
	done

.for __target in all fetch package extract configure build clean \
		cleandir distclean depend describe reinstall tags checksum \
		makedistinfo makepatchsum makesum mirror-distfiles deinstall \
		show-downlevel show-pkgsrc-dir show-var show-vars \
		fetch-list-one-pkg \
		fetch-list-recursive update clean-update lint \
		check-vulnerable pbulk-index \
		${PKG_MISC_TARGETS}
.if !target(__target)
.PHONY: ${__target}
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
	@${RECURSIVE_MAKE} ${MAKEFLAGS} README.html _README_TYPE_FLAG=--ftp _README_TYPE=$@
.endif

.if !target(cdrom-readme)
cdrom-readme:
	@${RECURSIVE_MAKE} ${MAKEFLAGS} README.html _README_TYPE_FLAG=--cdrom README_TYPE=$@
.endif

.if defined(PKGSRCTOP)
README=	templates/README.top
.else
README=	../templates/README.category
.endif

HTMLIFY=	${SED} -e 's/&/\&amp;/g' -e 's/>/\&gt;/g' -e 's/</\&lt;/g'

show-comment:
	@if [ ${COMMENT:Q}"" ]; then					\
		${ECHO} ${COMMENT:Q};					\
	elif [ -f COMMENT ] ; then					\
		${CAT} COMMENT;						\
	else								\
		${ECHO} '(no description)';				\
	fi

.if !target(show-distfiles)
show-distfiles:
	@for entry in ${SUBDIR}; do					\
		if [ -d ${.CURDIR}/$${entry}.${MACHINE} ]; then		\
			edir=$${entry}.${MACHINE};			\
		elif [ -d ${.CURDIR}/$${entry} ]; then			\
			edir=$${entry};					\
		else							\
			OK="false";					\
			${ECHO_MSG} "===> ${_THISDIR_}$${entry} non-existent"; \
		fi;							\
		if [ "$$OK" = "" ]; then				\
			cd ${.CURDIR}/$${edir} && ${RECURSIVE_MAKE} ${MAKEFLAGS} show-distfiles; \
		fi;							\
	done
.endif

.PHONY: show-subdir-var
show-subdir-var:
	@${ECHO} ${${VARNAME}:Q}

# Print out a script to fetch all needed files (no checksumming).
#
# When invoked at the top or category level, this target needs to be
# handled specially, to elide the "===>" messages that would otherwise
# ruin the script.
#
.if !target(fetch-list)
.PHONY: fetch-list

fetch-list:
	@${ECHO} '#!/bin/sh'
	@${ECHO} '#'
	@${ECHO} '# This is an auto-generated script, the result of running'
	@${ECHO} '# `make fetch-list'"'"' in directory "'"`${PWD_CMD}`"'"'
	@${ECHO} '# on host "'"`${UNAME} -n`"'" on "'"`date`"'".'
	@${ECHO} '#'
.if defined(PKGSRCTOP) && !defined(SPECIFIC_PKGS)
#	Recursing over dependencies would be pointless, in this case.
	@${RECURSIVE_MAKE} ${MAKEFLAGS} fetch-list-one-pkg	\
	| ${AWK} '						\
	function do_block () {					\
		if (FoundSomething) {				\
			for (line = 0; line < c; line++)	\
				print block[line];		\
			FoundSomething = 0			\
			}					\
		c = 0						\
		}						\
	/^[^#=]/ { FoundSomething = 1 }				\
	/^unsorted/ { gsub(/[[:space:]]+/, " \\\n\t") }		\
	/^echo/ { gsub(/;[[:space:]]+/, "\n") }			\
	!/^=/ { block[c++] = $$0 }				\
	/^=/ { do_block() }					\
	END { do_block() }					\
	'
.else
	@${RECURSIVE_MAKE} ${MAKEFLAGS} fetch-list-recursive	\
	| ${SED} '/^=/d'
.endif
.endif # !target(fetch-list)
