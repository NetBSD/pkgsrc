# $NetBSD: buildlink3.mk,v 1.29 2021/04/13 13:34:17 nia Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.50
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala
BUILDLINK_DEPMETHOD.vala?=	build

VALAC=		${PREFIX}/bin/valac-0.50
VAPIGEN=	${PREFIX}/bin/vapigen-0.50
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=	VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
