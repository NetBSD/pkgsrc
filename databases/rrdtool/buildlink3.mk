# $NetBSD: buildlink3.mk,v 1.2 2004/02/09 23:56:32 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RRDTOOL_BUILDLINK3_MK:=	${RRDTOOL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	rrdtool
.endif

.if !empty(RRDTOOL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		rrdtool
BUILDLINK_DEPENDS.rrdtool+=	rrdtool>=1.0.40nb2
BUILDLINK_PKGSRCDIR.rrdtool?=	../../databases/rrdtool

.  include "../../graphics/freetype-lib/buildlink3.mk"
.  include "../../graphics/gd/buildlink3.mk"
.  include "../../graphics/jpeg/buildlink3.mk"
.  include "../../www/cgilib/buildlink3.mk"
.endif # RRDTOOL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
