# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/04 23:38:39 dmcmahill Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GUILE16_BUILDLINK3_MK:=	${GUILE16_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	guile16
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguile16}
BUILDLINK_PACKAGES+=	guile16
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}guile16

.if !empty(GUILE16_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.guile16+=	guile16>=1.6.8
BUILDLINK_ABI_DEPENDS.guile16+=	guile16>=1.6.8
BUILDLINK_PKGSRCDIR.guile16?=	../../lang/guile16

BUILDLINK_PASSTHRU_DIRS=	${LOCALBASE}/guile/1.6
BUILDLINK_FILES.guile16+=	guile/1.6/bin/*
BUILDLINK_FNAME_TRANSFORM.guile16+=	-e s,/guile/1.6/bin/,/bin/,

GUILE16_SUBDIR=                 guile/1.6
.endif	# GUILE16_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
