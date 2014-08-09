# $NetBSD: buildlink3.mk,v 1.1 2014/08/09 22:12:56 wiz Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala024>=0.24
BUILDLINK_ABI_DEPENDS.vala+=	vala024>=0.24
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala024

VALAC=${LOCALBASE}/bin/valac-0.24
VAPIGEN=${LOCALBASE}/bin/vapigen-0.24
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+= VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
