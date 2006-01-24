# $NetBSD: buildlink3.mk,v 1.4 2006/01/24 07:32:20 wiz Exp $
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
BUILDLINK_RECOMMENDED.scilab?=	scilab>=3.1.1nb1
BUILDLINK_PKGSRCDIR.scilab?=	../../math/scilab

BUILDLINK_FILES.scilab+=	lib/scilab-${SCIVERSION}/Version.incl
.endif	# SCILAB_BUILDLINK3_MK

# do I really need these?
.include "../../parallel/pvm3/buildlink3.mk"
.include "../../textproc/sablotron/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

SCI=	${BUILDLINK_DIR}/lib/scilab-3.1.1
CONFIGURE_ENV+=	SCI=${SCI:Q}
MAKE_ENV+=	SCI=${SCI:Q}

SCIVERSION=	3.1.1

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
