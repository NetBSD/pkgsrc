# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:10 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGLADE2_BUILDLINK3_MK:=	${LIBGLADE2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglade2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibglade2}
BUILDLINK_PACKAGES+=	libglade2

.if !empty(LIBGLADE2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libglade2+=	libglade2>=2.0.1nb13
BUILDLINK_PKGSRCDIR.libglade2?=	../../devel/libglade2
BUILDLINK_INCDIRS.libglade2?=	include/libglade-2.0
.endif	# LIBGLADE2_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
