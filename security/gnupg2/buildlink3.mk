# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:17 joerg Exp $

BUILDLINK_TREE+=	gnupg2

.if !defined(GNUPG2_BUILDLINK3_MK)
GNUPG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnupg2+=	gnupg2>=2.0.0
BUILDLINK_PKGSRCDIR.gnupg2?=	../../security/gnupg2
BUILDLINK_PREFIX.gnupg2?=	${LOCALBASE}

pkgbase:=	gnupg2
.include "../../mk/pkg-build-options.mk"

.   if !empty(PKG_BUILD_OPTIONS.gnupg2:Midea)
pkgbase:=	libgcrypt
.   	include "../../mk/pkg-build-options.mk"
.   	if empty(PKG_BUILD_OPTIONS.libgcrypt:Midea)
PKGSRC_MAKE_ENV+=	PKG_OPTIONS.libgcrypt+=idea
.   	endif
.   endif

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # GNUPG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnupg2
