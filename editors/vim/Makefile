# $NetBSD: Makefile,v 1.32 2000/02/18 14:37:43 pooka Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-${VIM_VERSION}

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share

CONFLICTS=		vim-xaw-* vim-gtk-*

CONFIGURE_ARGS+=	--enable-gui=no --without-x
CPPFLAGS+=              -I${LOCALBASE}/include  # for ncurses' termcap.h
LDFLAGS+=               -L${LOCALBASE}/lib      # for -lncurses
CONFIGURE_ENV+=         CPPFLAGS="${CPPFLAGS}"

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
DEPENDS+=               ncurses>=4.2:../../devel/ncurses
CONFIGURE_ARGS+=	--with-tlib=ncurses
.elif ${OPSYS} == "SunOS"
CPPFLAGS=
CONFIGURE_ARGS+=	--with-tlib=curses
.endif

post-install:
	for f in rvim rview ; do				\
		${RM} -f ${PREFIX}/bin/$$f;			\
		${LN} -s vim ${PREFIX}/bin/$$f;			\
	done

.include "../../mk/bsd.pkg.mk"
