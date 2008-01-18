# $NetBSD: buildlink3.mk,v 1.5 2008/01/18 05:06:42 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBKEXIV2_BUILDLINK3_MK:=	${LIBKEXIV2_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libkexiv2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibkexiv2}
BUILDLINK_PACKAGES+=	libkexiv2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libkexiv2

.if ${LIBKEXIV2_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libkexiv2+=	libkexiv2>=0.1.1
BUILDLINK_ABI_DEPENDS.libkexiv2+=	libkexiv2>=0.1.6nb2
BUILDLINK_PKGSRCDIR.libkexiv2?=	../../graphics/libkexiv2
.endif	# LIBKEXIV2_BUILDLINK3_MK

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
