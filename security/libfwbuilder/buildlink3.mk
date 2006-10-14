# $NetBSD: buildlink3.mk,v 1.17 2006/10/14 01:42:51 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBFWBUILDER_BUILDLINK3_MK:=	${LIBFWBUILDER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libfwbuilder
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibfwbuilder}
BUILDLINK_PACKAGES+=	libfwbuilder
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libfwbuilder

.if !empty(LIBFWBUILDER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libfwbuilder+=	libfwbuilder>=2.0.12
BUILDLINK_ABI_DEPENDS.libfwbuilder+=	libfwbuilder>=2.0.12
BUILDLINK_PKGSRCDIR.libfwbuilder?=	../../security/libfwbuilder
.endif	# LIBFWBUILDER_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
