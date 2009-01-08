# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/08 00:21:00 jmcneill Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PACKAGEKIT_BUILDLINK3_MK:=	${PACKAGEKIT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	packagekit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npackagekit}
BUILDLINK_PACKAGES+=	packagekit
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}packagekit

.if ${PACKAGEKIT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.packagekit+=	packagekit>=0.4.0
BUILDLINK_PKGSRCDIR.packagekit?=	../../pkgtools/packagekit
.endif	# PACKAGEKIT_BUILDLINK3_MK

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
