# $NetBSD: Makefile,v 1.28 1999/12/21 17:18:59 pooka Exp $

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
	@${LN} -fs vim ${PREFIX}/bin/ex
	@${LN} -fs vim ${PREFIX}/bin/view
	@${LN} -fs vim ${PREFIX}/bin/rvim
	@${LN} -fs vim ${PREFIX}/bin/rview

.include "../../mk/bsd.pkg.mk"
