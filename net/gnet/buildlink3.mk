# $NetBSD: buildlink3.mk,v 1.1 2004/02/14 17:56:42 minskim Exp $
#
# This Makefile fragment is included by packages that use gnet.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNET_BUILDLINK3_MK:=	${GNET_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnet
.endif

.if !empty(GNET_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnet
BUILDLINK_DEPENDS.gnet+=		gnet>=2.0.3nb1
BUILDLINK_PKGSRCDIR.gnet?=		../../net/gnet

.include "../../devel/glib2/buildlink3.mk"

.endif # GNET_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
