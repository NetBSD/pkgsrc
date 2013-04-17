# $NetBSD: buildlink3.mk,v 1.1 2013/04/17 00:51:20 rodent Exp $

BUILDLINK_TREE+=	ucommon

.if !defined(UCOMMON_BUILDLINK3_MK)
UCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ucommon+=	ucommon>=5.0.6
BUILDLINK_PKGSRCDIR.ucommon?=	../../devel/ucommon

.include "../../mk/dlopen.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # UCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ucommon
