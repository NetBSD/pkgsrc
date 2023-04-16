# $NetBSD: buildlink3.mk,v 1.1 2023/04/16 20:14:47 gutteridge Exp $

BUILDLINK_TREE+=	acl

.if !defined(ACL_BUILDLINK3_MK)
ACL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.acl+=	acl>=2.2.52
BUILDLINK_PKGSRCDIR.acl?=	../../sysutils/acl

.include "../../sysutils/attr/buildlink3.mk"
.endif	# ACL_BUILDLINK3_MK

BUILDLINK_TREE+=	-acl
