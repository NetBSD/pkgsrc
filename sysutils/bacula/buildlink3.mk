# $NetBSD: buildlink3.mk,v 1.4 2025/09/07 03:37:07 jnemeth Exp $

BUILDLINK_TREE+=	bacula

.if !defined(BACULA_BUILDLINK3_MK)
BACULA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bacula+=	{bacula,bacula-clientonly}>=3.0.1nb1
BUILDLINK_ABI_DEPENDS.bacula?=	bacula>=15.0.3nb1
BUILDLINK_PKGSRCDIR.bacula?=	../../sysutils/bacula
.endif	# BACULA_BUILDLINK3_MK

BUILDLINK_TREE+=	-bacula
