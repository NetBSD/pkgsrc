# $NetBSD: Makefile,v 1.27 1999/12/21 13:18:05 pooka Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-${VIM_VERSION}

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share

CONFLICTS=		vim-xaw-* vim-gtk-*

CONFIGURE_ARGS+=	--disable-gui --with-tlib=ncurses
CPPFLAGS+=              -I${LOCALBASE}/include  # for ncurses' termcap.h
LDFLAGS+=               -L${LOCALBASE}/lib      # for -lncurses
CONFIGURE_ENV+=         CPPFLAGS="${CPPFLAGS}"

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
DEPENDS+=               ncurses-4.2:../../devel/ncurses
.endif

post-install:
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/ex
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/view
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/rvim
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/rview

.include "../../mk/bsd.pkg.mk"
