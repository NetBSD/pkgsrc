# $NetBSD: buildlink3.mk,v 1.4 2008/01/28 20:34:54 adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBFWBUILDER21_BUILDLINK3_MK:=	${LIBFWBUILDER21_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libfwbuilder21
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibfwbuilder21}
BUILDLINK_PACKAGES+=	libfwbuilder21
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libfwbuilder21

.if !empty(LIBFWBUILDER21_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libfwbuilder21+=	libfwbuilder21>=2.1.16
BUILDLINK_ABI_DEPENDS.libfwbuilder21+=	libfwbuilder21>=2.1.16
BUILDLINK_PKGSRCDIR.libfwbuilder21?=	../../security/libfwbuilder21
.endif	# LIBFWBUILDER21_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
