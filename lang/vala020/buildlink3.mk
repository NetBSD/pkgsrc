# $NetBSD: buildlink3.mk,v 1.1 2013/04/21 12:05:47 drochner Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala020>=0.20
BUILDLINK_ABI_DEPENDS.vala+=	vala020>=0.20
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala020

VALAC=${LOCALBASE}/bin/valac-0.20
VAPIGEN=${LOCALBASE}/bin/vapigen-0.20
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+= VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
