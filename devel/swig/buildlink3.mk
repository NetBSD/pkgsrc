# $NetBSD: buildlink3.mk,v 1.13 2022/05/19 09:03:53 jperkin Exp $

BUILDLINK_TREE+=	swig

.if !defined(SWIG_BUILDLINK3_MK)
SWIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig+=	swig>=1.3.24<2.0
BUILDLINK_ABI_DEPENDS.swig+=	swig>=1.3.31<2.0
BUILDLINK_PKGSRCDIR.swig?=	../../devel/swig
# only contains a static library
BUILDLINK_DEPMETHOD.swig?=	build

BUILDLINK_FILES.swig+=		share/swig/1.3/*.* share/swig/1.3/*/*.*
.endif # SWIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig
