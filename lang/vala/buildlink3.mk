# $NetBSD: buildlink3.mk,v 1.19 2018/04/17 04:20:07 wiz Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.40
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala

VALAC=		${LOCALBASE}/bin/valac-0.40
VAPIGEN=	${LOCALBASE}/bin/vapigen-0.40
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=	VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
