# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/14 22:57:10 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TELEPATHY_GLIB_BUILDLINK3_MK:=	${TELEPATHY_GLIB_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	telepathy-glib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntelepathy-glib}
BUILDLINK_PACKAGES+=	telepathy-glib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}telepathy-glib

.if ${TELEPATHY_GLIB_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.telepathy-glib+=	telepathy-glib>=0.7.18
BUILDLINK_PKGSRCDIR.telepathy-glib?=	../../chat/telepathy-glib
.endif	# TELEPATHY_GLIB_BUILDLINK3_MK

PRINT_PLIST_AWK+=	/^@dirrm include\/telepathy-1.0$$/ \
			{ print "@comment in telepathy-glib: " $$0; next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
