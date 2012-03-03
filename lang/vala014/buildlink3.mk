# $NetBSD: buildlink3.mk,v 1.2 2012/03/03 00:11:59 wiz Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala014>=0.14
BUILDLINK_ABI_DEPENDS.vala?=	vala014>=0.14.2nb1
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala014

VALAC=${LOCALBASE}/bin/valac-0.14
VAPIGEN=${LOCALBASE}/bin/vapigen-0.14
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+= VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
