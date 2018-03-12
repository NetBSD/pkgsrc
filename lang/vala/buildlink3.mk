# $NetBSD: buildlink3.mk,v 1.18 2018/03/12 11:15:38 wiz Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.38
BUILDLINK_ABI_DEPENDS.vala?=	vala>=0.38.8nb1
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala

VALAC=		${LOCALBASE}/bin/valac-0.38
VAPIGEN=	${LOCALBASE}/bin/vapigen-0.38
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=	VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
