# $NetBSD: buildlink3.mk,v 1.6 2004/10/03 00:13:23 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RRDTOOL_BUILDLINK3_MK:=	${RRDTOOL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	rrdtool
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrrdtool}
BUILDLINK_PACKAGES+=	rrdtool

.if !empty(RRDTOOL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.rrdtool+=	rrdtool>=1.0.40
BUILDLINK_RECOMMENDED.rrdtool+=	rrdtool>=1.0.40nb4
BUILDLINK_PKGSRCDIR.rrdtool?=	../../databases/rrdtool
.endif	# RRDTOOL_BUILDLINK3_MK

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../www/cgilib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
