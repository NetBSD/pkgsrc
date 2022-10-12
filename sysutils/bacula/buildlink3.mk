# $NetBSD: buildlink3.mk,v 1.3 2022/10/12 20:56:41 markd Exp $

BUILDLINK_TREE+=	bacula

.if !defined(BACULA_BUILDLINK3_MK)
BACULA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bacula+=	{bacula,bacula-clientonly}>=3.0.1nb1
BUILDLINK_ABI_DEPENDS.bacula?=	{bacula,bacula-clientonly}>=13.0.1
BUILDLINK_PKGSRCDIR.bacula?=	../../sysutils/bacula
.endif	# BACULA_BUILDLINK3_MK

BUILDLINK_TREE+=	-bacula
