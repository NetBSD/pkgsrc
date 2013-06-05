# $NetBSD: buildlink3.mk,v 1.1 2013/06/05 19:49:36 khorben Exp $
#

BUILDLINK_TREE+=	ssdeep

.if !defined(SSDEEP_BUILDLINK3_MK)
SSDEEP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ssdeep+=	ssdeep>=2.9
BUILDLINK_ABI_DEPENDS.ssdeep+=	ssdeep>=2.9
BUILDLINK_PKGSRCDIR.ssdeep?=	../../security/ssdeep
.endif # SSDEEP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ssdeep
