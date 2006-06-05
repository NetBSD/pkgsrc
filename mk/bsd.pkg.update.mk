# $NetBSD: bsd.pkg.update.mk,v 1.3 2006/06/05 17:21:54 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and contains the targets
# and variables for "make update".
#
# There is no documentation on what "update" actually does.  This is merely
# an attempt to separate the magic into a separate module that can be
# reimplemented later.
#

NOCLEAN?=	NO	# don't clean up after update
REINSTALL?=	NO	# reinstall upon update

# UPDATE_TARGET is the target that is invoked when updating packages during
# a "make update".  This variable is user-settable within /etc/mk.conf.
#
.if !defined(UPDATE_TARGET)
.  if defined(DEPENDS_TARGET) && (${DEPENDS_TARGET} == "update")
.    if make(package)
UPDATE_TARGET=	package
.    else
UPDATE_TARGET=	install
.    endif
.  else
UPDATE_TARGET=	${DEPENDS_TARGET}
.  endif
.endif

# The 'update' target can be used to update a package and all
# currently installed packages that depend upon this package.

_DDIR=	${WRKDIR}/.DDIR
_DLIST=	${WRKDIR}/.DLIST

.PHONY: update
.if !target(update)
.if exists(${_DDIR})
RESUMEUPDATE?=	YES
CLEAR_DIRLIST?=	NO

update:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_MSG}				\
		"${_PKGSRC_IN}> Resuming update for ${PKGNAME}"
.  if ${REINSTALL} != "NO" && ${UPDATE_TARGET} != "replace"
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} deinstall _UPDATE_RUNNING=YES DEINSTALLDEPENDS=ALL
.  endif
.else
RESUMEUPDATE?=	NO
CLEAR_DIRLIST?=	YES

update:
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} ${_DDIR}
.  if ${UPDATE_TARGET} != "replace"
	${_PKG_SILENT}${_PKG_DEBUG}if ${PKG_INFO} -qe ${PKGBASE}; then	\
		${MAKE} ${MAKEFLAGS} deinstall _UPDATE_RUNNING=YES DEINSTALLDEPENDS=ALL \
		|| (${RM} ${_DDIR} && ${FALSE});			\
	fi
.  endif
.endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} ${UPDATE_TARGET} KEEP_WRKDIR=YES	\
			DEPENDS_TARGET=${DEPENDS_TARGET:Q}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	[ ! -s ${_DDIR} ] || for dep in `${CAT} ${_DDIR}` ; do		\
		(if cd ../.. && cd "$${dep}" ; then			\
			${ECHO_MSG} "${_PKGSRC_IN}> Installing in $${dep}" && \
			if [ "(" "${RESUMEUPDATE}" = "NO" -o 		\
			     "${REINSTALL}" != "NO" ")" -a		\
			     "${UPDATE_TARGET}" != "replace" ] ; then	\
				${MAKE} ${MAKEFLAGS} deinstall _UPDATE_RUNNING=YES; \
			fi &&						\
			${MAKE} ${MAKEFLAGS} ${UPDATE_TARGET}		\
				DEPENDS_TARGET=${DEPENDS_TARGET:Q} ;	\
		else							\
			${ECHO_MSG} "${_PKGSRC_IN}> Skipping removed directory $${dep}"; \
		fi) ;							\
	done
.if ${NOCLEAN} == "NO"
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} clean-update CLEAR_DIRLIST=YES
.endif


.PHONY: clean-update
clean-update:
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} ${_DDIR}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -s ${_DDIR} ] ; then					\
		for dep in `${CAT} ${_DDIR}` ; do			\
			(if cd ../.. && cd "$${dep}" ; then		\
				${MAKE} ${MAKEFLAGS} clean ;		\
			else						\
				${ECHO_MSG} "${_PKGSRC_IN}> Skipping removed directory $${dep}";\
			fi) ;						\
		done ;							\
	fi
.if ${CLEAR_DIRLIST} != "NO"
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} clean
.else
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} clean update-dirlist		\
		DIRLIST="`${CAT} ${_DDIR}`" PKGLIST="`${CAT} ${_DLIST}`"
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_MSG}				\
		"${_PKGSRC_IN}> Warning: preserved leftover directory list.  Your next";\
		${ECHO_MSG} "${_PKGSRC_IN}>          \`\`${MAKE} update'' may fail.  It is advised to use";\
		${ECHO_MSG} "${_PKGSRC_IN}>          \`\`${MAKE} update REINSTALL=YES'' instead!"
.endif

.endif	# !target(update)


.PHONY: update-dirlist
update-dirlist:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} -p ${WRKDIR}
.if defined(PKGLIST)
.  for __tmp__ in ${PKGLIST}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} >>${_DLIST} "${__tmp__}"
.  endfor
.endif
.if defined(DIRLIST)
.  for __tmp__ in ${DIRLIST}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} >>${_DDIR} "${__tmp__}"
.  endfor
.endif


${_DDIR}: ${_DLIST}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	ddir=`${SED} 's:-[^-]*$$::' ${_DLIST}`;				\
	${ECHO} >${_DDIR};						\
	for pkg in $${ddir} ; do					\
		if ${PKG_INFO} -b "$${pkg}" >/dev/null 2>&1 ; then	\
			${PKG_INFO} -b "$${pkg}" | ${SED}	-ne	\
			    's,\([^/]*/[^/]*\)/Makefile:.*,\1,p' | 	\
			    ${HEAD} -1 >>${_DDIR};			\
		fi ;							\
	done

${_DLIST}: ${WRKDIR}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	{ ${PKG_DELETE} -n "${PKGWILDCARD}" 2>&1 | 			\
		${GREP} '^	' |					\
		${AWK} '{ l[NR]=$$0 } END { for (i=NR;i>0;--i) print l[i] }' \
	|| ${TRUE}; } > ${_DLIST}
