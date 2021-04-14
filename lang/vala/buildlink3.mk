# $NetBSD: buildlink3.mk,v 1.30 2021/04/14 07:27:56 wiz Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.52
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala
BUILDLINK_DEPMETHOD.vala?=	build

VALAC=		${PREFIX}/bin/valac-0.52
VAPIGEN=	${PREFIX}/bin/vapigen-0.52
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=	VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
