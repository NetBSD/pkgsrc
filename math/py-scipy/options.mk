# $NetBSD: options.mk,v 1.2 2025/08/20 12:19:23 adam Exp $

# Not making that option dependent on python version. Would only
# confuse, no?
PKG_OPTIONS_VAR=	PKG_OPTIONS.scipy

# Could be that we need BLAS directly here, too?

PKG_SUPPORTED_OPTIONS=  suitesparse
PKG_SUGGESTED_OPTIONS=
.include "../../mk/bsd.options.mk"

# The picture is blurry. It _seems_ that scipy itself does not actually
# use suitesparse (at last UMFPACK), but add-on-packages named scikits
# do. Wasn't the world complicated enough, already? I'll just ensure
# that suitesparse is present for those add-ons and perhaps also
# for parts of scipy itself (in future? now?).
.if !empty(PKG_OPTIONS:Msuitesparse)
.include "../../math/suitesparse/buildlink3.mk"
.endif
