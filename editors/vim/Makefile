# $NetBSD: Makefile,v 1.33 2000/06/25 11:50:32 pooka Exp $

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

.if ${OPSYS} == "NetBSD"
GOOD_CURSES=    1.4[Y-Z] 1.4Z[A-Z] 1.[5-9]*

.for PATTERN in ${GOOD_CURSES}
.if ${OS_VERSION:M${PATTERN}} != ""
CURSES_GOOD?=   #defined
.endif
.endfor
.endif

.if ${OPSYS} == "SunOS"
CURSES_GOOD?=	#defined
.endif

.if defined(CURSES_GOOD)
CPPFLAGS=
CONFIGURE_ARGS+=	--with-tlib=curses
.else
DEPENDS+=               ncurses>=4.2:../../devel/ncurses
CONFIGURE_ARGS+=	--with-tlib=ncurses
.endif

post-install:
	for f in rvim rview ; do				\
		${RM} -f ${PREFIX}/bin/$$f;			\
		${LN} -s vim ${PREFIX}/bin/$$f;			\
	done

.include "../../mk/bsd.pkg.mk"
