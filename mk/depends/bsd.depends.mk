# $NetBSD: bsd.depends.mk,v 1.2 2006/06/05 17:21:55 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to dependencies.
#
# The following are the "public" targets provided by this module:
#
#    depends, install-depends
#

_DEPENDS_COOKIE=	${WRKDIR}/.depends_done

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
.  elif make(bin-install) || make(real-su-bin-install)
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
.if defined(NO_DEPENDS)
depends: depends-cookie
.else
.  include "${PKGSRCDIR}/mk/depends/depends.mk"
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
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${_DEPENDS_COOKIE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RMDIR} -p ${_DEPENDS_COOKIE:H} 2>/dev/null || ${TRUE}

######################################################################
### depends-cookie (PRIVATE, override)
######################################################################
### depends-cookie creates the depends "cookie" state file.  This should
### be overridden per package system flavor.
###
.if !target(depends-cookie)
.PHONY: depends-cookie
depends-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${_DEPENDS_COOKIE:H}
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_ARGS} ${_DEPENDS_COOKIE}
.endif
