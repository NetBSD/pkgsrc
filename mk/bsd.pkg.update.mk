# $NetBSD: bsd.pkg.update.mk,v 1.26 2014/02/14 07:14:23 obache Exp $
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
.    if make(package) || make(package-install)
UPDATE_TARGET=	package-install
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

.PHONY: update-create-ddir
update-create-ddir: ${_DDIR}

.PHONY: update
.if !target(update)
.if exists(${_DDIR})
RESUMEUPDATE?=	YES
CLEAR_DIRLIST?=	NO

update:
	@${PHASE_MSG} "Resuming update for ${PKGNAME}"
.  if ${REINSTALL} != "NO" && ${UPDATE_TARGET} != "replace"
	${RUN} ${RECURSIVE_MAKE} ${MAKEFLAGS} deinstall _UPDATE_RUNNING=YES DEINSTALLDEPENDS=ALL
.  endif
.else
RESUMEUPDATE?=	NO
CLEAR_DIRLIST?=	YES

update:
	${RUN} ${RECURSIVE_MAKE} ${MAKEFLAGS} check-vulnerable
	${RUN} ${RECURSIVE_MAKE} ${MAKEFLAGS} update-create-ddir
.  if ${UPDATE_TARGET} != "replace"
	${RUN} if ${PKG_INFO} -qe ${PKGBASE}; then			\
		${RECURSIVE_MAKE} ${MAKEFLAGS} deinstall _UPDATE_RUNNING=YES DEINSTALLDEPENDS=ALL \
		|| (${RM} ${_DDIR} && ${FALSE});			\
	fi
.  endif
.endif
	${RUN} ${RECURSIVE_MAKE} ${MAKEFLAGS} ${UPDATE_TARGET} KEEP_WRKDIR=YES DEPENDS_TARGET=${DEPENDS_TARGET:Q}
	${RUN}					\
	[ ! -s ${_DDIR} ] || for dep in `${CAT} ${_DDIR}` ; do		\
		(if cd ../.. && cd "$${dep}" ; then			\
			${PHASE_MSG} "Installing in $${dep}" &&		\
			if [ "(" "${RESUMEUPDATE}" = "NO" -o 		\
			     "${REINSTALL}" != "NO" ")" -a		\
			     "${UPDATE_TARGET}" != "replace" ] ; then	\
				${RECURSIVE_MAKE} ${MAKEFLAGS} deinstall _UPDATE_RUNNING=YES; \
			fi &&						\
			${RECURSIVE_MAKE} ${MAKEFLAGS} ${UPDATE_TARGET}	\
				_PKGSRC_UPDATE_CHECK=yes		\
				DEPENDS_TARGET=${DEPENDS_TARGET:Q} ;	\
		else							\
			${PHASE_MSG} "Skipping removed directory $${dep}"; \
		fi) ;							\
	done
.if ${NOCLEAN} == "NO"
	${RUN} ${RECURSIVE_MAKE} ${MAKEFLAGS} clean-update CLEAR_DIRLIST=YES
.endif


.PHONY: clean-update
clean-update:
	${RUN} ${RECURSIVE_MAKE} ${MAKEFLAGS} update-create-ddir
	${RUN}					\
	if [ -s ${_DDIR} ] ; then					\
		for dep in `${CAT} ${_DDIR}` ; do			\
			(if cd ../.. && cd "$${dep}" ; then		\
				${RECURSIVE_MAKE} ${MAKEFLAGS} clean ;	\
			else						\
				${PHASE_MSG} "Skipping removed directory $${dep}";\
			fi) ;						\
		done ;							\
	fi
.if ${CLEAR_DIRLIST} != "NO"
	${RUN} ${RECURSIVE_MAKE} ${MAKEFLAGS} clean
.else
	${RUN} ${RECURSIVE_MAKE} ${MAKEFLAGS} clean update-dirlist DIRLIST="`${CAT} ${_DDIR}`" PKGLIST="`${CAT} ${_DLIST}`"
	@${WARNING_MSG} "preserved leftover directory list.  Your next"
	@${WARNING_MSG} "\`\`${MAKE} update'' may fail.  It is advised to use"
	@${WARNING_MSG} "\`\`${MAKE} update REINSTALL=YES'' instead!"
.endif

.endif	# !target(update)


.PHONY: update-dirlist
update-dirlist:
	${RUN} ${MKDIR} ${WRKDIR}
.if defined(PKGLIST)
.  for __tmp__ in ${PKGLIST}
	${RUN} ${ECHO} >>${_DLIST} "${__tmp__}"
.  endfor
.endif
.if defined(DIRLIST)
.  for __tmp__ in ${DIRLIST}
	${RUN} ${ECHO} >>${_DDIR} "${__tmp__}"
.  endfor
.endif


${_DDIR}: ${_DLIST}
	${RUN} pkgs=`${CAT} ${_DLIST}`;					\
	if [ "$$pkgs" ]; then ${PKG_INFO} -Q PKGPATH $$pkgs; fi > ${_DDIR}

${_DLIST}: ${WRKDIR}
	${RUN} if ${PKG_INFO} -qe "${PKGWILDCARD}"; then \
		${PKG_INFO} -qr "${PKGWILDCARD}" > ${_DLIST}; \
	else \
		${TOUCH} ${_DLIST}; \
	fi
