# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:38 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSOUP_BUILDLINK3_MK:=	${LIBSOUP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsoup
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsoup}
BUILDLINK_PACKAGES+=	libsoup

.if !empty(LIBSOUP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libsoup+=	libsoup>=1.99.26
BUILDLINK_PKGSRCDIR.libsoup?=	../../net/libsoup

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif	# LIBSOUP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
