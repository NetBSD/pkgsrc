# $NetBSD: Makefile,v 1.37 2001/02/16 14:40:54 wiz Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-${VIM_VERSION}

COMMENT=		Vim editor (vi clone) without gui

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share

CONFLICTS=		vim-xaw-* vim-gtk-*

CONFIGURE_ARGS+=	--enable-gui=no --without-x

USE_CURSES=		yes

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

post-install:
	for f in rvim rview ; do				\
		${RM} -f ${PREFIX}/bin/$$f;			\
		${LN} -s vim ${PREFIX}/bin/$$f;			\
	done

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+=	--with-tlib=ncurses
CPPFLAGS+=              -I${LOCALBASE}/include  # for ncurses' termcap.h
LDFLAGS+=               -L${LOCALBASE}/lib      # for -lncurses
CONFIGURE_ENV+=         CPPFLAGS="${CPPFLAGS}"
.else
CONFIGURE_ARGS+=	--with-tlib=curses
.endif

.include "../../mk/bsd.pkg.mk"
