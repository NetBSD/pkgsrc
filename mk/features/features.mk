# $NetBSD: features.mk,v 1.1 2007/09/07 21:55:47 jlam Exp $
#
# This file is included by bsd.pkg.mk.
#
# Variables defined by this file:
#
# FEATURE_CPPFLAGS
# FEATURE_LDFLAGS
# FEATURE_LIBS
#	Preprocessor and linker flags needed to build and to link against
#	the headers and libraries that supply the features missing from
#	the system.
#

.if defined(MISSING_FEATURES)
#
#	Handle "inet6" feature specially -- "inet6" could be in
#	MISSING_FEATURES even though it's not requested in USE_FEATURES
#	so check that it appears in both before failing the package
#	build.
#
.  if defined(USE_FEATURES) && !empty(USE_FEATURES:Minet6)
.    if !empty(MISSING_FEATURES:Minet6)
PKG_FAIL_REASON+=	"${PKGNAME} requires IPv6 support"
.    endif
.  endif

FEATURE_CPPFLAGS=	# empty
FEATURE_LDFLAGS=	# empty
FEATURE_LIBS=		# empty

.  if !empty(MISSING_FEATURES:Merr) || \
      !empty(MISSING_FEATURES:Mgetopt_long) || \
      !empty(MISSING_FEATURES:Mglob) || \
      !empty(MISSING_FEATURES:Mnbcompat) || \
      !empty(MISSING_FEATURES:Mregex) || \
      !empty(MISSING_FEATURES:Msnprintf) || \
      !empty(MISSING_FEATURES:Mutimes) || \
      !empty(MISSING_FEATURES:Mvsnprintf) || \
      !empty(MISSING_FEATURES:Mwarn)
_FEATURE_NEED_NBCOMPAT=		yes
.  endif
_FEATURE_NEED_NBCOMPAT?=	no

.  if ${_FEATURE_NEED_NBCOMPAT} == "yes"
.    include "${PKGSRCDIR}/pkgtools/libnbcompat/inplace.mk"
FEATURE_LIBS+=		${LDADD.nbcompat}
.  endif

.endif	# MISSING_FEATURES
