# $NetBSD: Makefile,v 1.7 1999/12/21 16:20:24 pooka Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-gtk-${VIM_VERSION}

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share \
			gtk+-1.2.*:../../x11/gtk
CONFLICTS=		vim-[0-9]* vim-gtk-*

DISTFILES+=		${DISTNAME}-rt${EXTRACT_SUFX}

USE_X11=		yes

CONFIGURE_ARGS+=	--enable-gui=gtk --with-tlib=ncurses
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses' termcap.h
LDFLAGS+=		-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=		ncurses-4.2:../../devel/ncurses
.endif

post-install:
	@if [ -f ${PREFIX}/man/man1/vim.1.gz ]; then                           \
		${LN} ${PREFIX}/man/man1/vim.1.gz ${PREFIX}/man/man1/gvim.1;   \
		${LN} ${PREFIX}/man/man1/vim.1.gz ${PREFIX}/man/man1/gview.1;  \
		${LN} ${PREFIX}/man/man1/vim.1.gz ${PREFIX}/man/man1/rgvim.1;  \
		${LN} ${PREFIX}/man/man1/vim.1.gz ${PREFIX}/man/man1/rgview.1; \
	else                                                                   \
		${LN} ${PREFIX}/man/man1/vim.1 ${PREFIX}/man/man1/gvim.1;      \
		${LN} ${PREFIX}/man/man1/vim.1 ${PREFIX}/man/man1/gview.1;     \
		${LN} ${PREFIX}/man/man1/vim.1 ${PREFIX}/man/man1/rgvim.1;     \
		${LN} ${PREFIX}/man/man1/vim.1 ${PREFIX}/man/man1/rgview.1;    \
	fi
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/gvim
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/gview
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/rgvim
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/rgview
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/ex
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/view
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/rvim
	@${LN} ${PREFIX}/bin/vim ${PREFIX}/bin/rview

.include "../../mk/bsd.pkg.mk"
