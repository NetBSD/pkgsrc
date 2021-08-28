# $NetBSD: buildlink3.mk,v 1.4 2021/08/28 18:34:09 bacon Exp $

BUILDLINK_TREE+=		libxtend

.if !defined(LIBXTEND_BUILDLINK3_MK)
LIBXTEND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxtend+=	libxtend>=0.1.3
BUILDLINK_PKGSRCDIR.libxtend?=		../../devel/libxtend
.endif	# LIBXTEND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxtend
