# $NetBSD: Makefile,v 1.6 2004/04/25 01:46:11 snj Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-motif-${VIM_VERSION}.${VIM_PATCHLEVEL}
PKGREVISION=		1

COMMENT=		Vim editor (vi clone) with X11 Motif GUI

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}:../vim-share
CONFLICTS+=		vim-[0-9]* vim-gtk-[0-9]* vim-gtk2-[0-9]*
CONFLICTS+=		vim-xaw-[0-9]*

USE_X11=		yes
CONFIGURE_ARGS+=	--enable-gui=motif
CONFIGURE_ARGS+=	--with-tlib=ncurses

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

post-install:
	for f in gvim.1 gview.1 rgvim.1 rgview.1; do			\
		${RM} -f ${PREFIX}/man/man1/$$f;			\
		${LN} -s vim.1 ${PREFIX}/man/man1/$$f;			\
	done
	for f in gvim gview rgvim rgview rvim rview; do			\
		${RM} -f ${PREFIX}/bin/$$f;				\
		${LN} -s vim ${PREFIX}/bin/$$f;				\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
