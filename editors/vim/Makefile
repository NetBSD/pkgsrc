# $NetBSD: Makefile,v 1.45 2003/06/02 08:26:03 martti Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-${VIM_VERSION}.${VIM_PATCHLEVEL}

COMMENT=		Vim editor (vi clone) without gui

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}:../vim-share

CONFLICTS+=		vim-gtk-[0-9]* vim-gtk2-[0-9]* vim-motif-[0-9]*
CONFLICTS+=		vim-xaw-[0-9]*

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
