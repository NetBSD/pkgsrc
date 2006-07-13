# $NetBSD: bsd.depends.mk,v 1.9 2006/07/13 14:02:34 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to dependencies.
#
# The following are the "public" targets provided by this module:
#
#    depends, bootstrap-depends, install-depends
#

# DEPENDS_TARGET is the target that is invoked to satisfy missing
# dependencies.  This variable is user-settable in /etc/mk.conf.
#
.if !defined(DEPENDS_TARGET)
.  if make(package)
DEPENDS_TARGET=		package
.  elif make(update)
.    if defined(UPDATE_TARGET) && (${UPDATE_TARGET} == "replace")
DEPENDS_TARGET=		${UPDATE_TARGET}
.    else
DEPENDS_TARGET=		update
.    endif
.  elif make(bin-install) || make(su-bin-install)
DEPENDS_TARGET=		bin-install
.  else
DEPENDS_TARGET=		reinstall
.  endif
.endif

######################################################################
### depends (PUBLIC)
######################################################################
### depends is a public target to install missing dependencies for
### the package.
###
.PHONY: depends
.if !defined(NO_DEPENDS)
.  include "${PKGSRCDIR}/mk/depends/depends.mk"
.elif !target(depends)
.  if exists(${_COOKIE.depends})
depends:
	@${DO_NADA}
.  else
depends: depends-cookie
.  endif
.endif

######################################################################
### bootstrap-depends (PUBLIC, OVERRIDE)
######################################################################
### bootstrap-depends is a public target to install any missing
### dependencies needed during stages before the normal "depends"
### stage.  These dependencies are listed in BOOTSTRAP_DEPENDS.
###
.PHONY: bootstrap-depends
.if !target(bootstrap-depends)
bootstrap-depends:
	@${DO_NADA}
.endif

######################################################################
### install-depends (PUBLIC)
######################################################################
### install-depends is a convenience target that installs all dependencies
### and removes the cookie file afterwards, so that the state of the
### filesystem remains unchanged.
###
### XXX This target is probably not needed and might be removed.
###
.PHONY: install-depends
install-depends: depends depends-clean

######################################################################
### depends-clean (PRIVATE)
######################################################################
### depends-clean removes the state files associated with the "depends"
### target so that "depends" may be re-invoked.
###
depends-clean:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${_COOKIE.depends}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RMDIR} -p ${_COOKIE.depends:H} 2>/dev/null || ${TRUE}

######################################################################
### depends-cookie (PRIVATE, override)
######################################################################
### depends-cookie creates the depends "cookie" state file.  This should
### be overridden per package system flavor.
###
.PHONY: depends-cookie
.if !target(depends-cookie)
depends-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}${TEST} ! -f ${_COOKIE.depends} || ${FALSE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${_COOKIE.depends:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${_COOKIE.depends}
.endif
