# $NetBSD: Makefile,v 1.9 2000/11/02 03:25:33 wiz Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-xaw-${VIM_VERSION}

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share
CONFLICTS=		vim-[0-9]* vim-gtk-*

USE_X11=		yes
USE_XAW=		yes
USE_CURSES=		yes

CONFIGURE_ARGS+=	--enable-gui=athena
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses' termcap.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

post-install:
	for f in gvim.1 gview.1 rgvim.1 rgview.1; do			\
		${RM} -f ${PREFIX}/man/man1/$$f;			\
		${LN} -s vim.1 ${PREFIX}/man/man1/$$f;			\
	done
	for f in gvim gview rgvim rgview rvim rview; do			\
		${RM} -f ${PREFIX}/bin/$$f;				\
		${LN} -s vim ${PREFIX}/bin/$$f;				\
	done

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+=	--with-tlib=ncurses
.else
CPPFLAGS=
CONFIGURE_ARGS+=	--with-tlib=curses
.endif

.include "../../mk/bsd.pkg.mk"

.if (${XAW_TYPE} == "standard")
MAKE_ENV+=		XAW_LIB=Xaw
.else
MAKE_ENV+=		XAW_LIB=Xaw3d
.endif
