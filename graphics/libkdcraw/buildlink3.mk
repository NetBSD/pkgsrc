# $NetBSD: buildlink3.mk,v 1.4 2008/01/18 05:06:42 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBKDCRAW_BUILDLINK3_MK:=	${LIBKDCRAW_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libkdcraw
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibkdcraw}
BUILDLINK_PACKAGES+=	libkdcraw
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libkdcraw

.if ${LIBKDCRAW_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=0.1.1
BUILDLINK_ABI_DEPENDS.libkdcraw?=	libkdcraw>=0.1.3nb1
BUILDLINK_PKGSRCDIR.libkdcraw?=	../../graphics/libkdcraw
.endif	# LIBKDCRAW_BUILDLINK3_MK

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
