# $NetBSD: buildlink3.mk,v 1.6 2021/12/14 18:55:11 bacon Exp $

BUILDLINK_TREE+=		libxtend

.if !defined(LIBXTEND_BUILDLINK3_MK)
LIBXTEND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxtend+=	libxtend>=0.1.4
BUILDLINK_PKGSRCDIR.libxtend?=		../../devel/libxtend
.endif	# LIBXTEND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxtend
