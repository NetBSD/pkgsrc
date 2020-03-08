# $NetBSD: buildlink3.mk,v 1.24 2020/03/08 16:47:52 wiz Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.46
BUILDLINK_ABI_DEPENDS.vala?=	vala>=0.46.6nb1
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala

VALAC=		${PREFIX}/bin/valac-0.46
VAPIGEN=	${PREFIX}/bin/vapigen-0.46
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=	VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
