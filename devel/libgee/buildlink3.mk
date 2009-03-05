# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/05 21:59:43 ahoka Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGEE_BUILDLINK3_MK:=	${LIBGEE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libgee
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgee}
BUILDLINK_PACKAGES+=	libgee
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgee

.if ${LIBGEE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libgee+=	libgee>=0.1.5
BUILDLINK_PKGSRCDIR.libgee?=	../../devel/libgee
.endif	# LIBGEE_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
