# $NetBSD: buildlink3.mk,v 1.1 2018/12/14 16:02:55 bsiegert Exp $

BUILDLINK_TREE+=	libunrar

.if !defined(LIBUNRAR_BUILDLINK3_MK)
LIBUNRAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunrar+=	libunrar>=5.6.8
BUILDLINK_PKGSRCDIR.libunrar?=	../../archivers/libunrar
.endif	# LIBUNRAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunrar
