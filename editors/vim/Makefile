# $NetBSD: Makefile,v 1.41 2001/09/27 23:18:02 jlam Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-${VIM_VERSION}

COMMENT=		Vim editor (vi clone) without gui

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share

CONFLICTS+=		vim-xaw-[0-9]* vim-gtk-[0-9]*

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
