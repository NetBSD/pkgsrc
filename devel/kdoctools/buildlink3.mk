# $NetBSD: buildlink3.mk,v 1.24 2021/12/08 16:01:54 adam Exp $

BUILDLINK_TREE+=	kdoctools

.if !defined(KDOCTOOLS_BUILDLINK3_MK)
KDOCTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdoctools+=	kdoctools>=5.21.0
BUILDLINK_ABI_DEPENDS.kdoctools?=	kdoctools>=5.80.0nb2
BUILDLINK_PKGSRCDIR.kdoctools?=		../../devel/kdoctools

BUILDLINK_FILES.kdoctools+=		share/kf5/kdoctools/customization/*.xsl

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDOCTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdoctools
