# $NetBSD: buildlink3.mk,v 1.5 2022/02/08 10:26:16 mcf Exp $

BUILDLINK_TREE+=	guile22

.if !defined(GUILE22_BUILDLINK3_MK)
GUILE22_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile22+=	guile22>=2.2
BUILDLINK_ABI_DEPENDS.guile22?=	guile22>=2.2.7nb3
BUILDLINK_PKGSRCDIR.guile22?=	../../lang/guile22

BUILDLINK_PASSTHRU_DIRS+=		${PREFIX}/guile/2.2
BUILDLINK_FILES.guile22+=		guile/2.2/bin/*
BUILDLINK_FNAME_TRANSFORM.guile22+=	-e s,guile/2.2/bin,bin,
BUILDLINK_FNAME_TRANSFORM.guile22+=	-e s,guile/2.2/lib/pkgconfig,lib/pkgconfig,

GUILE22_SUBDIR=				guile/2.2

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.endif # GUILE22_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile22
