# $NetBSD: Makefile,v 1.40 2001/08/06 17:44:44 pooka Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-${VIM_VERSION}

COMMENT=		Vim editor (vi clone) without gui

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share

CONFLICTS+=		vim-xaw-* vim-gtk-*

USE_BUILDLINK_ONLY=	# defined

CONFIGURE_ARGS+=	--enable-gui=no --without-x
CONFIGURE_ARGS+=	--with-tlib=ncurses

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

post-install:
	for f in rvim rview ; do				\
		${RM} -f ${PREFIX}/bin/$$f;			\
		${LN} -s vim ${PREFIX}/bin/$$f;			\
	done

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
