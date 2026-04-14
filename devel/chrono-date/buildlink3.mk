# $NetBSD: buildlink3.mk,v 1.1 2026/04/14 12:46:17 kikadf Exp $

BUILDLINK_TREE+=	chrono-date

.if !defined(CHRONO_DATE_BUILDLINK3_MK)
CHRONO_DATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chrono-date+=	chrono-date>=3.0.4
BUILDLINK_ABI_DEPENDS.chrono-date+=	chrono-date>=3.0.4
BUILDLINK_PKGSRCDIR.chrono-date?=	../../devel/chrono-date

.endif # CHRONO_DATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-chrono-date
