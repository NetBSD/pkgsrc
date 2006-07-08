# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 22:39:33 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSOUP_BUILDLINK3_MK:=	${LIBSOUP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsoup
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsoup}
BUILDLINK_PACKAGES+=	libsoup
BUILDLINK_ORDER+=	libsoup

.if !empty(LIBSOUP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libsoup+=	libsoup>=1.99.28nb3
BUILDLINK_ABI_DEPENDS.libsoup?=	libsoup>=1.99.28nb4
BUILDLINK_PKGSRCDIR.libsoup?=	../../net/libsoup
.endif	# LIBSOUP_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
