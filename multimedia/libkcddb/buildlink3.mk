# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:25 rillig Exp $

BUILDLINK_TREE+=	libkcddb

.if !defined(LIBKCDDB_BUILDLINK3_MK)
LIBKCDDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkcddb+=	libkcddb>=4.10.2
BUILDLINK_PKGSRCDIR.libkcddb?=		../../multimedia/libkcddb

.endif	# LIBKCDDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkcddb
