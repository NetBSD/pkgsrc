# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:24:50 joerg Exp $

BUILDLINK_TREE+=	guile

.if !defined(GUILE_BUILDLINK3_MK)
GUILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile+=	guile>=1.8.1
BUILDLINK_ABI_DEPENDS.guile+=	guile>=1.8.1
BUILDLINK_PKGSRCDIR.guile?=	../../lang/guile

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GUILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile
