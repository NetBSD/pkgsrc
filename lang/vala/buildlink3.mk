# $NetBSD: buildlink3.mk,v 1.11 2014/11/01 10:25:20 prlw1 Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.26
BUILDLINK_ABI_DEPENDS.vala+=	vala>=0.26
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala

VALAC=${LOCALBASE}/bin/valac-0.26
VAPIGEN=${LOCALBASE}/bin/vapigen-0.26
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=	VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
