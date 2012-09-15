# $NetBSD: buildlink3.mk,v 1.3 2012/09/15 10:05:22 obache Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala016>=0.16
BUILDLINK_ABI_DEPENDS.vala+=	vala016>=0.16.1nb1
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala016

VALAC=${LOCALBASE}/bin/valac-0.16
VAPIGEN=${LOCALBASE}/bin/vapigen-0.16
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+= VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
