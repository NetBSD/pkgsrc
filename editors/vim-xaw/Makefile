# $NetBSD: Makefile,v 1.7 2000/06/25 11:50:40 pooka Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-xaw-${VIM_VERSION}

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share
CONFLICTS=		vim-[0-9]* vim-gtk-*

USE_X11=		yes
USE_XAW=		yes

CONFIGURE_ARGS+=	--enable-gui=athena
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses' termcap.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
GOOD_CURSES=    1.4[Y-Z] 1.4Z[A-Z] 1.[5-9]*

.for PATTERN in ${GOOD_CURSES}
.if ${OS_VERSION:M${PATTERN}} != ""
CURSES_GOOD?=   #defined
.endif
.endfor
.endif

.if ${OPSYS} == "SunOS"
CURSES_GOOD?=   #defined
.endif

.if defined(CURSES_GOOD)
CPPFLAGS=
CONFIGURE_ARGS+=        --with-tlib=curses
.else
DEPENDS+=               ncurses>=4.2:../../devel/ncurses
CONFIGURE_ARGS+=        --with-tlib=ncurses
.endif

post-install:
	for f in gvim.1 gview.1 rgvim.1 rgview.1; do			\
		${RM} -f ${PREFIX}/man/man1/$$f;			\
		${LN} -s vim.1 ${PREFIX}/man/man1/$$f;			\
	done
	for f in gvim gview rgvim rgview rvim rview; do			\
		${RM} -f ${PREFIX}/bin/$$f;				\
		${LN} -s vim ${PREFIX}/bin/$$f;				\
	done

.include "../../mk/bsd.pkg.mk"

.if (${XAW_TYPE} == "standard")
MAKE_ENV+=		XAW_LIB=Xaw
.else
MAKE_ENV+=		XAW_LIB=Xaw3d
.endif
