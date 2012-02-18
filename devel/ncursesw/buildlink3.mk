# $NetBSD: buildlink3.mk,v 1.6 2012/02/18 10:19:04 obache Exp $

BUILDLINK_TREE+=	ncursesw

.if !defined(NCURSESW_BUILDLINK3_MK)
NCURSESW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncursesw+=	ncursesw>=5.5
BUILDLINK_ABI_DEPENDS.ncursesw+=	ncursesw>=5.5
BUILDLINK_PKGSRCDIR.ncursesw?=		../../devel/ncursesw

BUILDLINK_LIBNAME.ncursesw=	ncursesw
BUILDLINK_LDADD.ncursesw=	${BUILDLINK_LIBNAME.ncursesw:S/^/-l/:S/^-l$//}

CHECK_BUILTIN.ncursesw:=	yes
.  include "builtin.mk"
CHECK_BUILTIN.ncursesw:=	no
.  if defined(IS_BUILTIN.ncursesw) && !empty(IS_BUILTIN.ncursesw:M[nN][oO])
PKG_BUILD_DEPENDS.ncurses!=	\
	echo "";		\
	${PKG_INFO} -qn ncursesw 2> /dev/null \
	|| { cd ../../devel/ncursesw && ${MAKE} ${MAKEFLAGS} show-depends; }
.    for d in ${PKG_BUILD_DEPENDS.ncurses:Mncurses[-><]*}
BUILDLINK_API_DEPENDS.ncurses+=	${d}
.    endfor
USE_NCURSES=			yes
.  endif

.include "../../devel/ncurses/buildlink3.mk"
.endif # NCURSESW_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncursesw
