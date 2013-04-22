# $NetBSD: buildlink3.mk,v 1.2 2013/04/22 06:10:42 rodent Exp $

BUILDLINK_TREE+=	libzrtpcpp

.if !defined(LIBZRTPCPP_BUILDLINK3_MK)
LIBZRTPCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzrtpcpp+=	libzrtpcpp>=0.9.0
BUILDLINK_ABI_DEPENDS.libzrtpcpp?=	libzrtpcpp>=1.4.6nb1
BUILDLINK_PKGSRCDIR.libzrtpcpp?=	../../net/libzrtpcpp

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../net/ccrtp/buildlink3.mk"
.endif # LIBZRTPCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzrtpcpp
