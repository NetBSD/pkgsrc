# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:18:15 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGTOP_BUILDLINK3_MK:=	${LIBGTOP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgtop
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgtop}
BUILDLINK_PACKAGES+=	libgtop

.if !empty(LIBGTOP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgtop+=	libgtop>=1.0.13nb4
BUILDLINK_RECOMMENDED.libgtop+=	libgtop>=1.0.13nb5
BUILDLINK_PKGSRCDIR.libgtop?=	../../sysutils/libgtop
.endif	# LIBGTOP_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
