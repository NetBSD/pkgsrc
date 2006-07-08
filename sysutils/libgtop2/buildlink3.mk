# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:11:09 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGTOP2_BUILDLINK3_MK:=	${LIBGTOP2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgtop2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgtop2}
BUILDLINK_PACKAGES+=	libgtop2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgtop2

.if !empty(LIBGTOP2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgtop2+=	libgtop2>=2.14.0
BUILDLINK_PKGSRCDIR.libgtop2?=	../../sysutils/libgtop2
.endif	# LIBGTOP2_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
