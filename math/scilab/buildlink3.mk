# $NetBSD: buildlink3.mk,v 1.1 2004/08/13 00:51:10 dmcmahill Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SCILAB_BUILDLINK3_MK:=	${SCILAB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	scilab
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nscilab}
BUILDLINK_PACKAGES+=	scilab

.if !empty(SCILAB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.scilab+=	scilab>=3.0
BUILDLINK_PKGSRCDIR.scilab?=	../../math/scilab
.endif	# SCILAB_BUILDLINK3_MK

# do I really need these?
.include "../../parallel/pvm3/buildlink3.mk"
.include "../../textproc/sablotron/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

SCI=	${BUILDLINK_DIR}/lib/scilab-3.0
CONFIGURE_ENV+=	SCI=${SCI}
MAKE_ENV+=	SCI=${SCI}

SCIVERSION=	3.0

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
