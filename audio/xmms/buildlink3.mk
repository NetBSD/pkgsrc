# $NetBSD: buildlink3.mk,v 1.1 2004/02/17 16:23:53 minskim Exp $
#
# This Makefile fragment is included by packages that use xmms.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XMMS_BUILDLINK3_MK:=	${XMMS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xmms
.endif

.if !empty(XMMS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			xmms
BUILDLINK_DEPENDS.xmms+=		xmms>=1.2.7nb10
BUILDLINK_PKGSRCDIR.xmms?=		../../audio/xmms

PTHREAD_OPTS+=	require

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif # XMMS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
