# $NetBSD: category.mk,v 1.2 2007/10/13 11:04:18 dsl Exp $
#
# This file contains the variables and targets for category Makefiles.
#

.include "common.mk"

README.html: .PRECIOUS .PHONY
	@> $@.tmp
.for entry in ${SUBDIR}
.if defined(PKGSRCTOP)
	@${ECHO} '<TR><TD VALIGN=TOP><a href="'${entry}/README.html'">'"`${ECHO} ${entry} | ${HTMLIFY}`"'</a>: <TD>' >> $@.tmp
	@${ECHO} `cd ${entry} && ${RECURSIVE_MAKE} ${MAKEFLAGS} show-comment | ${HTMLIFY}` >> $@.tmp
.else
	@${ECHO} '<TR><TD VALIGN=TOP><a href="'${entry}/README.html'">'"`cd ${entry}; ${RECURSIVE_MAKE} ${MAKEFLAGS} make-readme-html-help`" >> $@.tmp
.endif
.endfor
	@${SORT} -t '>' +3 -4 $@.tmp > $@.tmp2
	@${AWK} '{ ++n } END { print n }' < $@.tmp2 > $@.tmp4
.if exists(${.CURDIR}/DESCR)
	@${HTMLIFY} ${.CURDIR}/DESCR > $@.tmp3
.else
	@> $@.tmp3
.endif
	@${CAT} ${README} | \
		${SED} -e 's/%%CATEGORY%%/'"`${BASENAME} ${.CURDIR}`"'/g' \
			-e '/%%NUMITEMS%%/r$@.tmp4' \
			-e '/%%NUMITEMS%%/d' \
			-e '/%%DESCR%%/r$@.tmp3' \
			-e '/%%DESCR%%/d' \
			-e '/%%SUBDIR%%/r$@.tmp2' \
			-e '/%%SUBDIR%%/d' \
		> $@.tmp5
	@if [ -f $@ ] && ${CMP} -s $@.tmp5 $@ ; then \
		${RM} $@.tmp5 ; \
	else \
		${ECHO_MSG} "===>  Creating README.html for ${_THISDIR_}${.CURDIR:T}" ; \
		${MV} $@.tmp5 $@ ; \
	fi
	@${RM} -f $@.tmp $@.tmp2 $@.tmp3 $@.tmp4
.for subdir in ${SUBDIR}
	@cd ${subdir} && ${RECURSIVE_MAKE} ${MAKEFLAGS} "_THISDIR_=${_THISDIR_}${.CURDIR:T}/" ${_README_TYPE}
.endfor

.include "../bsd.pkg.subdir.mk"
