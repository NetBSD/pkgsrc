# $NetBSD: buildlink3.mk,v 1.11 2023/06/14 18:39:00 bacon Exp $

BUILDLINK_TREE+=		libxtend

.if !defined(LIBXTEND_BUILDLINK3_MK)
LIBXTEND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxtend+=	libxtend>=0.1.8
BUILDLINK_PKGSRCDIR.libxtend?=		../../devel/libxtend
.endif	# LIBXTEND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxtend
