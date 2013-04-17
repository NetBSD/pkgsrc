# $NetBSD: buildlink3.mk,v 1.1 2013/04/17 00:55:35 rodent Exp $

BUILDLINK_TREE+=	libzrtpcpp

.if !defined(LIBZRTPCPP_BUILDLINK3_MK)
LIBZRTPCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzrtpcpp+=	libzrtpcpp>=0.9.0
BUILDLINK_ABI_DEPENDS.libzrtpcpp?=	libzrtpcpp>=1.4.6nb1
BUILDLINK_PKGSRCDIR.libzrtpcpp?=	../../net/libzrtpcpp

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ucommon/buildlink3.mk"
.include "../../net/ccrtp/buildlink3.mk"
.endif # LIBZRTPCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzrtpcpp
