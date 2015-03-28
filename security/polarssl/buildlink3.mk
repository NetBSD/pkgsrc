# $NetBSD: buildlink3.mk,v 1.4 2015/03/28 19:05:50 rodent Exp $

BUILDLINK_TREE+=	polarssl

.if !defined(POLARSSL_BUILDLINK3_MK)
POLARSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polarssl+=	polarssl>=0.10.0
BUILDLINK_PKGSRCDIR.polarssl?=	../../security/polarssl

pkgbase := polarssl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.polarssl:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
.endif

.endif # POLARSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-polarssl
