# $NetBSD: Makefile,v 1.1.1.1 1999/12/21 13:26:28 pooka Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-xaw-${VIM_VERSION}

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share
CONFLICTS=		vim-[0-9]* vim-gtk-*

USE_X11=		yes
USE_XAW=		yes

CONFIGURE_ARGS+=	--enable-gui=athena --with-tlib=ncurses
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses' termcap.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
DEPENDS+=		ncurses-4.2:../../devel/ncurses
.endif

post-install:
	@${LN} ${PREFIX}/man/man1/vim.1 ${PREFIX}/man/man1/gvim.1
	@${LN} ${PREFIX}/man/man1/view.1 ${PREFIX}/man/man1/gview.1
	@${LN} ${PREFIX}/man/man1/rvim.1 ${PREFIX}/man/man1/rgvim.1
	@${LN} ${PREFIX}/man/man1/rview.1 ${PREFIX}/man/man1/rgview.1
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/gvim
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/gview
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/rgvim
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/rgview
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/ex
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/view
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/rvim
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/rview

.include "../../mk/bsd.pkg.mk"

.if (${XAW_TYPE} == "standard")
MAKE_ENV+=		XAW_LIB=Xaw
.else
MAKE_ENV+=		XAW_LIB=Xaw3d
.endif
