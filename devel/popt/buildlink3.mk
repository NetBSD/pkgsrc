# $NetBSD: buildlink3.mk,v 1.13 2011/04/22 13:41:58 obache Exp $

BUILDLINK_TREE+=	popt

.if !defined(POPT_BUILDLINK3_MK)
POPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.popt+=	popt>=1.7nb3
BUILDLINK_ABI_DEPENDS.popt+=	popt>=1.16nb1
BUILDLINK_PKGSRCDIR.popt?=	../../devel/popt

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # POPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-popt
