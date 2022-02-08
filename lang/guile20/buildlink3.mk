# $NetBSD: buildlink3.mk,v 1.6 2022/02/08 10:26:16 mcf Exp $

BUILDLINK_TREE+=	guile20

.if !defined(GUILE20_BUILDLINK3_MK)
GUILE20_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile20+=	guile20>=2.0
BUILDLINK_ABI_DEPENDS.guile20?=	guile20>=2.0.14nb3
BUILDLINK_PKGSRCDIR.guile20?=	../../lang/guile20

#BUILDLINK_PASSTHRU_DIRS+=		${LOCALBASE}/guile/2.0
#BUILDLINK_FILES.guile20+=		guile/2.0/bin/*
#BUILDLINK_FNAME_TRANSFORM.guile20+=	-e s,guile/2.0/bin,bin,
#BUILDLINK_FNAME_TRANSFORM.guile20+=	-e s,guile/2.0/lib/pkgconfig,lib/pkgconfig,
#
#GUILE20_SUBDIR=			guile/2.0

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.endif # GUILE20_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile20
