# $NetBSD: Makefile,v 1.30 2001/10/25 07:34:05 martti Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-gtk-${VIM_VERSION}

COMMENT=		Vim editor (vi clone) with X11 GTK+ GUI

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share
CONFLICTS+=		vim-[0-9]* vim-xaw-[0-9]*

USE_BUILDLINK_ONLY=	yes

CONFIGURE_ARGS+=	--enable-gui=gtk
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

.include "../../devel/ncurses/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
