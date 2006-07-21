# $NetBSD: buildlink3.mk,v 1.15 2006/07/21 16:17:55 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RRDTOOL_BUILDLINK3_MK:=	${RRDTOOL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	rrdtool
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrrdtool}
BUILDLINK_PACKAGES+=	rrdtool
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}rrdtool

.if ${RRDTOOL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.rrdtool+=	rrdtool>=1.2.9
BUILDLINK_ABI_DEPENDS.rrdtool+=	rrdtool>=1.2.12nb3
BUILDLINK_PKGSRCDIR.rrdtool?=	../../databases/rrdtool
.endif	# RRDTOOL_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../www/cgilib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
