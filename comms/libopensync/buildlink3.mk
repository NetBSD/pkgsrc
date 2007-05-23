# $NetBSD: buildlink3.mk,v 1.2 2007/05/23 21:27:26 seb Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBOPENSYNC_BUILDLINK3_MK:=	${LIBOPENSYNC_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libopensync
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibopensync}
BUILDLINK_PACKAGES+=	libopensync
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libopensync

.if ${LIBOPENSYNC_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libopensync+=	libopensync>=0.22
BUILDLINK_PKGSRCDIR.libopensync?=	../../comms/libopensync
.endif	# LIBOPENSYNC_BUILDLINK3_MK

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
