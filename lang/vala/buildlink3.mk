# $NetBSD: buildlink3.mk,v 1.27 2020/08/17 20:17:34 leot Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.48
BUILDLINK_ABI_DEPENDS.vala?=	vala>=0.48.7nb1
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
