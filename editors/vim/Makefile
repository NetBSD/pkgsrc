# $NetBSD: Makefile,v 1.43 2002/09/14 00:10:45 jlam Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-${VIM_VERSION}.${VIM_PATCHLEVEL}

COMMENT=		Vim editor (vi clone) without gui

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}:../vim-share

CONFLICTS+=		vim-xaw-[0-9]* vim-gtk-[0-9]*

CONFIGURE_ARGS+=	--enable-gui=no --without-x
CONFIGURE_ARGS+=	--with-tlib=ncurses

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

post-install:
	for f in rvim rview ; do				\
		${RM} -f ${PREFIX}/bin/$$f;			\
		${LN} -s vim ${PREFIX}/bin/$$f;			\
	done

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
