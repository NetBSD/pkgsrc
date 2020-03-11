# $NetBSD: buildlink3.mk,v 1.26 2020/03/11 09:53:51 wiz Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.48
BUILDLINK_ABI_DEPENDS.vala?=	vala>=0.48.0
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala

VALAC=		${PREFIX}/bin/valac-0.48
VAPIGEN=	${PREFIX}/bin/vapigen-0.48
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=	VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
