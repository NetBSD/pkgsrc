# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/20 17:36:14 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AVAHI_BUILDLINK3_MK:=	${AVAHI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	avahi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Navahi}
BUILDLINK_PACKAGES+=	avahi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}avahi

.if ${AVAHI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.avahi+=	avahi>=0.6.23
BUILDLINK_PKGSRCDIR.avahi?=	../../net/avahi
.endif	# AVAHI_BUILDLINK3_MK

pkgbase := avahi
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.avahi:Mgdbm)
.  include "../../databases/gdbm/buildlink3.mk"
.endif
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
