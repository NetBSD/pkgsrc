# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:35:53 wiz Exp $

BUILDLINK_TREE+=	bacula

.if !defined(BACULA_BUILDLINK3_MK)
BACULA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bacula+=	{bacula,bacula-clientonly}>=3.0.1nb1
BUILDLINK_ABI_DEPENDS.bacula?=	bacula>=9.6.7nb8
BUILDLINK_PKGSRCDIR.bacula?=	../../sysutils/bacula
.endif	# BACULA_BUILDLINK3_MK

BUILDLINK_TREE+=	-bacula
