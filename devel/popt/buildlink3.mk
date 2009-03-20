# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:24:26 joerg Exp $

BUILDLINK_TREE+=	popt

.if !defined(POPT_BUILDLINK3_MK)
POPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.popt+=	popt>=1.7nb3
BUILDLINK_ABI_DEPENDS.popt+=	popt>=1.7nb6
BUILDLINK_PKGSRCDIR.popt?=	../../devel/popt

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # POPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-popt
