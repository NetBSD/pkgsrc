# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:34:13 wiz Exp $

BUILDLINK_TREE+=	guile

.if !defined(GUILE_BUILDLINK3_MK)
GUILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile+=	guile18>=1.8.1
BUILDLINK_ABI_DEPENDS.guile+=	guile18>=1.8.8nb13
BUILDLINK_PKGSRCDIR.guile?=	../../lang/guile18

BUILDLINK_PASSTHRU_DIRS+=		${PREFIX}/guile/1.8
BUILDLINK_FILES.guile+=			guile/1.8/bin/*
BUILDLINK_FNAME_TRANSFORM.guile+=	-e s,guile/1.8/bin,bin,
BUILDLINK_FNAME_TRANSFORM.guile+=	-e s,guile/1.8/lib/pkgconfig,lib/pkgconfig,

GUILE_SUBDIR=				guile/1.8

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GUILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile
