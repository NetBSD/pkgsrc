# $NetBSD: buildlink3.mk,v 1.1 2013/04/03 12:23:51 markd Exp $

BUILDLINK_TREE+=	libkcddb

.if !defined(LIBKCDDB_BUILDLINK3_MK)
LIBKCDDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkcddb+=	libkcddb>=4.10.2
BUILDLINK_PKGSRCDIR.libkcddb?=	../../multimedia/libkcddb

.endif	# LIBKCDDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkcddb
