# $NetBSD: buildlink3.mk,v 1.4 2007/09/21 13:03:52 wiz Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSCIGRAPHICA_BUILDLINK3_MK:=	${LIBSCIGRAPHICA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libscigraphica
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibscigraphica}
BUILDLINK_PACKAGES+=	libscigraphica
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libscigraphica

.if ${LIBSCIGRAPHICA_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libscigraphica+=	libscigraphica>=2.1.1
BUILDLINK_PKGSRCDIR.libscigraphica?=	../../graphics/libscigraphica
.endif	# LIBSCIGRAPHICA_BUILDLINK3_MK

.include "../../graphics/libart/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2+extra/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
