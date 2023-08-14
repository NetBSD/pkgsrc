# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:24:39 wiz Exp $

BUILDLINK_TREE+=	hackrf

.if !defined(HACKRF_BUILDLINK3_MK)
HACKRF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hackrf+=	hackrf>=0.1
BUILDLINK_ABI_DEPENDS.hackrf+=	hackrf>=2023.01.1nb1
BUILDLINK_PKGSRCDIR.hackrf?=	../../ham/hackrf
.endif # HACKRF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hackrf
