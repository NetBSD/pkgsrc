# $NetBSD: deinstall.mk,v 1.8.14.1 2009/05/30 20:55:24 tron Exp $

# Set the appropriate flags to pass to pkg_delete(1) based on the value
# of DEINSTALLDEPENDS (see pkgsrc/mk/install/deinstall.mk).
#
.if defined(DEINSTALLDEPENDS)
.  if empty(DEINSTALLDEPENDS:M[nN][oO])
.    if !empty(DEINSTALLDEPENDS:M[aA][lL][lL])
_PKG_ARGS_DEINSTALL+=	-r	# for "update" target
.    else
_PKG_ARGS_DEINSTALL+=	-r -R	# for removing stuff in bulk builds
.    endif
.  endif
.endif

.if defined(PKG_VERBOSE)
_PKG_ARGS_DEINSTALL+=	-v
.endif

.if defined(PKG_PRESERVE)
.  if defined(_UPDATE_RUNNING) && !empty(_UPDATE_RUNNING:M[yY][eE][sS])
_PKG_ARGS_DEINSTALL+=	-N -f -f	# update w/o removing any files
.  endif
.endif

# _flavor-deinstall:
#	Removes a package from the system.
#
# See also:
#	deinstall
#
_flavor-deinstall: .PHONY
	${RUN}								\
	if [ x"${OLDNAME}" = x ]; then					\
		found=`${PKG_INFO} -e "${PKGNAME}" || ${TRUE}`;		\
	else								\
		found=${OLDNAME};					\
	fi;								\
	case "$$found" in						\
	"") found=`${_PKG_BEST_EXISTS} ${PKGWILDCARD:Q} || ${TRUE}`;;	\
	esac;								\
	if ${TEST} -n "$$found"; then					\
		${ECHO} "Running ${PKG_DELETE} ${_PKG_ARGS_DEINSTALL} $$found"; \
		${PKG_DELETE} ${_PKG_ARGS_DEINSTALL} "$$found" || ${TRUE} ; \
	fi
.if defined(DEINSTALLDEPENDS) && !empty(DEINSTALLDEPENDS:M[yY][eE][sS])
.  for _pkg_ in ${BUILD_DEPENDS:C/:.*$//}
	${RUN}								\
	found=`${_PKG_BEST_EXISTS} ${_pkg_:Q} || ${TRUE}`;		\
	if ${TEST} -n "$$found"; then					\
		${ECHO} "Running ${PKG_DELETE} ${_PKG_ARGS_DEINSTALL} $$found"; \
		${PKG_DELETE} ${_PKG_ARGS_DEINSTALL} "$$found" || ${TRUE}; \
	fi
.  endfor
.endif
