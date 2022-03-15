# $NetBSD: buildlink3.mk,v 1.7 2022/03/15 21:03:27 bacon Exp $

BUILDLINK_TREE+=		libxtend

.if !defined(LIBXTEND_BUILDLINK3_MK)
LIBXTEND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxtend+=	libxtend>=0.1.5
BUILDLINK_PKGSRCDIR.libxtend?=		../../devel/libxtend
.endif	# LIBXTEND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxtend
