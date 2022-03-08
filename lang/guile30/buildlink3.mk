# $NetBSD: buildlink3.mk,v 1.1 2022/03/08 00:09:30 wiz Exp $

BUILDLINK_TREE+=	guile30

.if !defined(GUILE30_BUILDLINK3_MK)
GUILE30_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile30+=	guile30>=3.0
BUILDLINK_PKGSRCDIR.guile30?=	../../lang/guile30

BUILDLINK_PASSTHRU_DIRS=		${PREFIX}/guile/3.0
BUILDLINK_FILES.guile30+=		guile/3.0/bin/*
BUILDLINK_FNAME_TRANSFORM.guile30+=	-e s,guile/3.0/bin,bin,
BUILDLINK_FNAME_TRANSFORM.guile30+=	-e s,guile/3.0/lib/pkgconfig,lib/pkgconfig,

GUILE30_SUBDIR=				guile/3.0

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.endif # GUILE30_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile30
