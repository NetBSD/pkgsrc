# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/02/07 01:48:22 joerg Exp $

BUILDLINK_DEPMETHOD.libfetch?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBFETCH_BUILDLINK3_MK:=	${LIBFETCH_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libfetch
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibfetch}
BUILDLINK_PACKAGES+=	libfetch
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libfetch

.if ${LIBFETCH_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libfetch+=	libfetch>=2.0
BUILDLINK_PKGSRCDIR.libfetch?=	../../net/libfetch
.endif	# LIBFETCH_BUILDLINK3_MK

pkgbase := libfetch
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libfetch:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
