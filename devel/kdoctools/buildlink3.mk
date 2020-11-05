# $NetBSD: buildlink3.mk,v 1.21 2020/11/05 09:06:47 ryoon Exp $

BUILDLINK_TREE+=	kdoctools

.if !defined(KDOCTOOLS_BUILDLINK3_MK)
KDOCTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdoctools+=	kdoctools>=5.21.0
BUILDLINK_ABI_DEPENDS.kdoctools?=	kdoctools>=5.70.0nb3
BUILDLINK_PKGSRCDIR.kdoctools?=		../../devel/kdoctools

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDOCTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdoctools
