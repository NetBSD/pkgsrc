# $NetBSD: buildlink3.mk,v 1.2 2025/04/29 11:59:51 adam Exp $

BUILDLINK_TREE+=	swig4

.if !defined(SWIG4_BUILDLINK3_MK)
SWIG4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig4+=	swig4>=4.1.1
BUILDLINK_PKGSRCDIR.swig4?=	../../devel/swig4

BUILDLINK_FILES.swig4+=		bin/ccache-swig4.0
BUILDLINK_FILES.swig4+=		bin/swig4.0

.include "../../devel/pcre2/buildlink3.mk"
.endif	# SWIG4_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig4
