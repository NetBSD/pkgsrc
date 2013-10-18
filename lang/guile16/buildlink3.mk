# $NetBSD: buildlink3.mk,v 1.4 2013/10/18 16:05:06 roy Exp $

BUILDLINK_TREE+=	guile16

.if !defined(GUILE16_BUILDLINK3_MK)
GUILE16_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile16+=	guile16>=1.6.8
BUILDLINK_ABI_DEPENDS.guile16+=	guile16>=1.6.8nb3
BUILDLINK_PKGSRCDIR.guile16?=	../../lang/guile16

BUILDLINK_PASSTHRU_DIRS=	${LOCALBASE}/guile/1.6
BUILDLINK_FILES.guile16+=	guile/1.6/bin/*
BUILDLINK_FNAME_TRANSFORM.guile16+=	-e s,/guile/1.6/bin/,/bin/,

GUILE16_SUBDIR=                 guile/1.6

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GUILE16_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile16
