# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/07/22 22:24:39 adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBTORRENT_BUILDLINK3_MK:=	${LIBTORRENT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtorrent
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtorrent}
BUILDLINK_PACKAGES+=	libtorrent

.if !empty(LIBTORRENT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libtorrent+=	libtorrent>=0.7.0
BUILDLINK_PKGSRCDIR.libtorrent?=	../../wip/libtorrent
.endif	# LIBTORRENT_BUILDLINK3_MK

.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
