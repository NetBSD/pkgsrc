# $NetBSD: buildlink3.mk,v 1.2 2013/01/26 04:35:37 obache Exp $

BUILDLINK_TREE+=	swig

.if !defined(SWIG_BUILDLINK3_MK)
SWIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig+=	swig>=2.0.4
BUILDLINK_PKGSRCDIR.swig?=	../../devel/swig2

.include "../../devel/pcre/buildlink3.mk"
.endif	# SWIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig
