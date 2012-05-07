# $NetBSD: buildlink3.mk,v 1.17 2012/05/07 01:53:41 dholland Exp $

BUILDLINK_TREE+=	kaffe

.if !defined(KAFFE_BUILDLINK3_MK)
KAFFE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kaffe+=	kaffe>=1.1.7
BUILDLINK_ABI_DEPENDS.kaffe+=	kaffe>=1.1.7
BUILDLINK_PKGSRCDIR.kaffe?=	../../lang/kaffe
BUILDLINK_JAVA_PREFIX.kaffe=	${PREFIX}/java/kaffe

BUILDLINK_CPPFLAGS.kaffe= \
	-I${BUILDLINK_JAVA_PREFIX.kaffe}/include			\
	-I${BUILDLINK_JAVA_PREFIX.kaffe}/include/kaffe
.endif # KAFFE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kaffe
