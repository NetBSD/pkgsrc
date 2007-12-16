# $NetBSD: buildlink3.mk,v 1.3 2007/12/16 13:55:48 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GDL_BUILDLINK3_MK:=	${GDL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gdl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngdl}
BUILDLINK_PACKAGES+=	gdl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gdl

.if ${GDL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gdl+=	gdl>=0.6.1
BUILDLINK_ABI_DEPENDS.gdl?=	gdl>=0.6.1nb2
BUILDLINK_PKGSRCDIR.gdl?=	../../devel/gdl
.endif	# GDL_BUILDLINK3_MK

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
