# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 03:06:30 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libsoup.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSOUP_BUILDLINK3_MK:=	${LIBSOUP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsoup
.endif

.if !empty(LIBSOUP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libsoup
BUILDLINK_DEPENDS.libsoup+=		libsoup>=1.99.26
BUILDLINK_PKGSRCDIR.libsoup?=		../../net/libsoup

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif # LIBSOUP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
