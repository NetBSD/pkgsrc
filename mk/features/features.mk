# $NetBSD: features.mk,v 1.13 2025/02/18 13:06:28 wiz Exp $
#
# This file is included by bsd.pkg.mk.
#

.if defined(MISSING_FEATURES)
#
#	Handle "inet6" feature specially -- "inet6" could be in
#	MISSING_FEATURES even though it's not requested in USE_FEATURES
#	so check that it appears in both before failing the package
#	build.
#
.  if !empty(USE_FEATURES:Minet6)
.    if !empty(MISSING_FEATURES:Minet6)
PKG_SKIP_REASON+=	"${PKGNAME} requires IPv6 support"
.    endif
.  endif

#
# libnbcompat provides many of the current features.
#
_FEATURE_USE_NBCOMPAT?=	no
.  for f in asprintf cdefs err fts_close fts_open fts_read fts_set getline getopt_long glob memrchr nbcompat regcomp setenv snprintf strndup strnlen utimes vsnprintf warn
.    if !empty(MISSING_FEATURES:M${f})
_FEATURE_USE_NBCOMPAT=	yes
.    endif
.  endfor

.  if ${_FEATURE_USE_NBCOMPAT} == "yes"
.    include "../../pkgtools/libnbcompat/buildlink3.mk"
.  endif

.endif	# MISSING_FEATURES
