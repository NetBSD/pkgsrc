# $NetBSD: buildlink3.mk,v 1.5 2004/04/01 18:32:03 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSOUP_BUILDLINK3_MK:=	${LIBSOUP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsoup
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsoup}
BUILDLINK_PACKAGES+=	libsoup

.if !empty(LIBSOUP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libsoup+=	libsoup>=2.1.8
BUILDLINK_PKGSRCDIR.libsoup?=	../../net/libsoup
.endif	# LIBSOUP_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
