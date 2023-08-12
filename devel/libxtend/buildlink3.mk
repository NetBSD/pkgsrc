# $NetBSD: buildlink3.mk,v 1.13 2023/08/12 14:46:26 bacon Exp $

BUILDLINK_TREE+=		libxtend

.if !defined(LIBXTEND_BUILDLINK3_MK)
LIBXTEND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxtend+=	libxtend>=0.1.9
BUILDLINK_PKGSRCDIR.libxtend?=		../../devel/libxtend
.endif	# LIBXTEND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxtend
