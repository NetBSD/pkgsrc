# $NetBSD: buildlink3.mk,v 1.20 2018/09/03 10:46:45 wiz Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.42
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala

VALAC=		${LOCALBASE}/bin/valac-0.42
VAPIGEN=	${LOCALBASE}/bin/vapigen-0.42
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=	VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
