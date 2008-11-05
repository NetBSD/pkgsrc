# $NetBSD: can-be-built-here.mk,v 1.6 2008/11/05 08:24:23 rillig Exp $
#
# This file checks whether a package can be built in the current pkgsrc
# environment. It checks the following variables:
#
# * NOT_FOR_COMPILER, ONLY_FOR_COMPILER
# * NOT_FOR_PLATFORM, ONLY_FOR_PLATFORM
# * NOT_FOR_BULK_PLATFORM
# * NOT_FOR_UNPRIVILEGED, ONLY_FOR_UNPRIVILEGED
# * PKG_FAIL_REASON, PKG_SKIP_REASON
#
# It also depends on the following internal variables:
#
# NO_SKIP
#	When defined, the checks in this file are skipped. It is called
#	NO_SKIP because the code that skips building the package should
#	_not_ be run.
#
#	XXX: It's weird to have three negations in such a short variable
#	name.
#

_CBBH_CHECKS=		# none, but see below.

# Check NOT_FOR_COMPILER
_CBBH_CHECKS+=		ncomp
_CBBH_MSGS.ncomp=	"This package is not available for these compilers: "${NOT_FOR_COMPILER:Q}"."

_CBBH.ncomp=		yes
.for c in ${NOT_FOR_COMPILER}
.  for pc in ${PKGSRC_COMPILER}
# The left-hand side of the == operator must be a "real" variable.
_c:= ${c}
.    if ${_c} == ${pc}
_CBBH.ncomp=		no
.    endif
.  endfor
.endfor

# Check ONLY_FOR_COMPILER
_CBBH_CHECKS+=		ocomp
_CBBH_MSGS.ocomp=	"This package is only available for these compilers: "${ONLY_FOR_COMPILER:Q}"."

_CBBH.ocomp=		yes
.if defined(ONLY_FOR_COMPILER) && !empty(ONLY_FOR_COMPILER)
_CBBH.ocomp=		yes
# Ignore compilers that only cache or distribute the real work that has
# to be done (see PR 35173).
.  for pc in ${PKGSRC_COMPILER:Nccache:Ndistcc}
.    if empty(ONLY_FOR_COMPILER:M${pc})
_CBBH.ocomp=		no
.    endif
.  endfor
.endif

# Check NOT_FOR_PLATFORM
_CBBH_CHECKS+=		nplat
_CBBH_MSGS.nplat=	"This package is not available for these platforms: "${NOT_FOR_PLATFORM:Q}"."

_CBBH.nplat=		yes
.for p in ${NOT_FOR_PLATFORM}
.  if !empty(MACHINE_PLATFORM:M${p})
_CBBH.nplat=		no
.  endif
.endfor

# Check NOT_FOR_BULK_PLATFORM
_CBBH_CHECKS+=		nbplat
_CBBH_MSGS.nbplat=	"This package is known to stall the bulk build on these platforms: "${NOT_FOR_BULK_PLATFORM:Q}"."

_CBBH.nbplat=		yes
.for p in ${NOT_FOR_BULK_PLATFORM}
.  if defined(BATCH) && !empty(MACHINE_PLATFORM:M${p})
_CBBH.nbplat=		no
.  endif
.endfor

# Check ONLY_FOR_PLATFORM
_CBBH_CHECKS+=		oplat
_CBBH_MSGS.oplat=	"This package is only available for these platforms: "${ONLY_FOR_PLATFORM:Q}"."

_CBBH.oplat=		yes
.if defined(ONLY_FOR_PLATFORM) && !empty(ONLY_FOR_PLATFORM)
_CBBH.oplat=		no
.  for p in ${ONLY_FOR_PLATFORM}
.    if !empty(MACHINE_PLATFORM:M${p})
_CBBH.oplat=		yes
.    endif
.  endfor
.endif

# Check NOT_FOR_UNPRIVILEGED
_CBBH_CHECKS+=		nunpriv
_CBBH_MSGS.nunpriv=	"This package is not available in unprivileged mode."

_CBBH.nunpriv=		yes
.if defined(NOT_FOR_UNPRIVILEGED) && !empty(NOT_FOR_UNPRIVILEGED:M[Yy][Ee][Ss])
.  if !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
_CBBH.nunpriv=		no
.  endif
.endif

# Check ONLY_FOR_UNPRIVILEGED
_CBBH_CHECKS+=		ounpriv
_CBBH_MSGS.ounpriv=	"This package is not available in unprivileged mode."

_CBBH.ounpriv=		yes
.if defined(ONLY_FOR_UNPRIVILEGED) && !empty(ONLY_FOR_UNPRIVILEGED:M[Yy][Ee][Ss])
.  if empty(UNPRIVILEGED:M[Yy][Ee][Ss])
_CBBH.ounpriv=		no
.  endif
.endif

# Check PKG_FAIL_REASON
_CBBH_CHECKS+=		fail
_CBBH_MSGS.fail=	"This package has set PKG_FAIL_REASON:" ${PKG_FAIL_REASON}

_CBBH.fail=		yes
.if defined(PKG_FAIL_REASON) && !empty(PKG_FAIL_REASON)
_CBBH.fail=		no
.endif

# Check PKG_SKIP_REASON
_CBBH_CHECKS+=		skip
_CBBH_MSGS.skip=	"This package has set PKG_SKIP_REASON:" ${PKG_SKIP_REASON}

_CBBH.skip=		yes
.if defined(PKG_SKIP_REASON) && !empty(PKG_SKIP_REASON)
_CBBH.skip=		no
.endif

# Check PKG_INSTALLATION_TYPES
_CBBH_CHECKS+=		pkgviews
_CBBH_MSGS.pkgviews=	"This package is not available for pkgviews."

_CBBH.pkgviews=		yes
.if ${PKG_INSTALLATION_PREFS} == "pkgviews overwrite"
.  if empty(PKG_INSTALLATION_TYPES:Mpkgviews)
_CBBH.pkgviews=		no
.  endif
.endif

# Collect and combine the results
_CBBH=			yes
_CBBH_MSGS=		# none
.for c in ${_CBBH_CHECKS}
.  if ${_CBBH.${c}} != "yes"
_CBBH=			no
_CBBH_MSGS+=		${_CBBH_MSGS.${c}}
.  endif
.endfor

# In the first line, this target prints either "yes" or "no", saying
# whether this package can be built. If the package can not be built,
# the reasons are given in the following lines.
#
can-be-built-here: .PHONY
	@${ECHO} ${_CBBH}
	@:; ${_CBBH_MSGS:@m@${ECHO} ${m} ; @}

_cbbh:
	@:; ${_CBBH_MSGS:@m@${ERROR_MSG} ${m} ; @}
	@${FALSE}

.if !defined(NO_SKIP) && ${_CBBH} == "no"
# XXX: bootstrap-depends is only used here because it is depended
# upon by each of the "main" pkgsrc targets.
bootstrap-depends: _cbbh
.endif
