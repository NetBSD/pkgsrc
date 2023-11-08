# $NetBSD: buildlink3.mk,v 1.32 2023/11/08 13:18:50 wiz Exp $

BUILDLINK_TREE+=	kdoctools

.if !defined(KDOCTOOLS_BUILDLINK3_MK)
KDOCTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdoctools+=	kdoctools>=5.21.0
BUILDLINK_ABI_DEPENDS.kdoctools?=	kdoctools>=5.108.0nb2
BUILDLINK_PKGSRCDIR.kdoctools?=		../../devel/kdoctools

BUILDLINK_FILES.kdoctools+=		share/kf5/kdoctools/customization/*.xsl

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDOCTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdoctools
