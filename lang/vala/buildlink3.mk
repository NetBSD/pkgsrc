# $NetBSD: buildlink3.mk,v 1.12 2015/04/03 07:38:17 wiz Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.28
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala

VALAC=${LOCALBASE}/bin/valac-0.28
VAPIGEN=${LOCALBASE}/bin/vapigen-0.28
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=	VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
