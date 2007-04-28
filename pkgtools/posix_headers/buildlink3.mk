# $NetBSD: buildlink3.mk,v 1.3 2007/04/28 21:03:56 tnn Exp $

BUILD_DEPENDS+=		posix_headers>=0.4nb5:../../pkgtools/posix_headers

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POSIX_HEADERS_BUILDLINK3_MK:=	${POSIX_HEADERS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
#BUILDLINK_DEPENDS+=	# intentionally left blank.
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nposix_headers}
BUILDLINK_PACKAGES+=	posix_headers
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}posix_headers

.if !empty(POSIX_HEADERS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.posix_headers+=	posix_headers>=0.1bogus
BUILDLINK_ABI_DEPENDS.posix_headers+=	posix_headers>=0.1bogus
BUILDLINK_PKGSRCDIR.posix_headers?=	../../pkgtools/posix_headers
.endif	# POSIX_HEADERS_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
