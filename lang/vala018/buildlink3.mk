# $NetBSD: buildlink3.mk,v 1.1 2012/10/09 10:56:14 drochner Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala018>=0.17
BUILDLINK_ABI_DEPENDS.vala+=	vala018>=0.17
BUILDLINK_PKGSRCDIR.vala?=	../../lang/vala018

VALAC=${LOCALBASE}/bin/valac-0.18
VAPIGEN=${LOCALBASE}/bin/vapigen-0.18
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+= VALAC=${VALAC} VAPIGEN=${VAPIGEN}
.endif

.include "../../devel/glib2/buildlink3.mk"
.endif	# VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
