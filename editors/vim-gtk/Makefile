# $NetBSD: Makefile,v 1.15 2000/02/15 16:08:23 agc Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-gtk-${VIM_VERSION}

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
CONFLICTS=		vim-[0-9]* vim-xaw-*

DISTFILES+=		${DISTNAME}-rt${EXTRACT_SUFX}

USE_X11=		yes

CONFIGURE_ARGS+=	--enable-gui=gtk
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses' termcap.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=		ncurses>=4.2:../../devel/ncurses
CONFIGURE_ARGS+=	--with-tlib=ncurses
.elif ${OPSYS} == "SunOS"
CPPFLAGS=
CONFIGURE_ARGS+=	--with-tlib=curses
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
