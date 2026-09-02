# $NetBSD: buildlink3.mk,v 1.4 2026/09/02 19:01:45 wiz Exp $

BUILDLINK_TREE+=	swig4

.if !defined(SWIG4_BUILDLINK3_MK)
SWIG4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swig4+=	swig4>=4.1.1
BUILDLINK_ABI_DEPENDS.swig4?=	swig4>=4.4.1nb1
BUILDLINK_PKGSRCDIR.swig4?=	../../devel/swig4

BUILDLINK_FILES.swig4+=		bin/ccache-swig4.0
BUILDLINK_FILES.swig4+=		bin/swig4.0

.include "../../devel/pcre2/buildlink3.mk"
.endif	# SWIG4_BUILDLINK3_MK

BUILDLINK_TREE+=	-swig4
