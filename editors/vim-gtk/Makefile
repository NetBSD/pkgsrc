# $NetBSD: Makefile,v 1.14 2000/02/15 15:44:15 agc Exp $

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
	${RM} -f ${PREFIX}/man/man1/gvim.1 ${PREFIX}/man/man1/gview.1
	${RM} -f ${PREFIX}/man/man1/rgvim.1 ${PREFIX}/man/man1/rgview.1
	${RM} -f ${PREFIX}/bin/gvim ${PREFIX}/bin/gview ${PREFIX}/bin/rgvim
	${RM} -f ${PREFIX}/bin/rgview ${PREFIX}/bin/rvim ${PREFIX}/bin/rview
	${LN} -s vim.1 ${PREFIX}/man/man1/gvim.1
	${LN} -s vim.1 ${PREFIX}/man/man1/gview.1
	${LN} -s vim.1 ${PREFIX}/man/man1/rgvim.1
	${LN} -s vim.1 ${PREFIX}/man/man1/rgview.1
	${LN} -s vim ${PREFIX}/bin/gvim
	${LN} -s vim ${PREFIX}/bin/gview
	${LN} -s vim ${PREFIX}/bin/rgvim
	${LN} -s vim ${PREFIX}/bin/rgview
	${LN} -s vim ${PREFIX}/bin/rvim
	${LN} -s vim ${PREFIX}/bin/rview

.include "../../mk/bsd.pkg.mk"
