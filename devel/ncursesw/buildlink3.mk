# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:24:24 joerg Exp $

BUILDLINK_TREE+=	ncursesw

.if !defined(NCURSESW_BUILDLINK3_MK)
NCURSESW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncursesw+=	ncursesw>=5.5
BUILDLINK_ABI_DEPENDS.ncursesw+=	ncursesw>=5.5
BUILDLINK_PKGSRCDIR.ncursesw?=		../../devel/ncursesw

BUILDLINK_LIBNAME.ncursesw=	ncursesw
BUILDLINK_LDADD.ncursesw=	${BUILDLINK_LIBNAME.ncursesw:S/^/-l/:S/^-l$//}

.include "../../devel/ncurses/buildlink3.mk"
.endif # NCURSESW_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncursesw
