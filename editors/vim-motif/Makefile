# $NetBSD: Makefile,v 1.23 2006/07/18 10:27:16 martti Exp $

PKGNAME=		vim-motif-${VIM_VERSION}.${VIM_PATCHLEVEL}
#PKGREVISION=		1

COMMENT=		Vim editor (vi clone) with X11 Motif GUI

.include "../../editors/vim-share/Makefile.common"

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share
CONFLICTS+=		vim-[0-9]* vim-gtk-[0-9]* vim-gtk2-[0-9]*
CONFLICTS+=		vim-xaw-[0-9]* vim-kde-[0-9]*

CONFIGURE_ARGS+=	--enable-gui=motif
CONFIGURE_ARGS+=	--with-tlib=ncurses

CONFIGURE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR:Q}
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR:Q}

BUILD_TARGET=		vim
INSTALL_TARGET=		installvimbin

post-install:
.for f in gvim.1 gview.1 rgvim.1 rgview.1
	${RM} -f ${PREFIX:Q}/man/man1/${f:Q}
	${LN} -s vim.1 ${PREFIX:Q}/man/man1/${f:Q}
.endfor
.for f in gvim gview rgvim rgview rvim rview
	${RM} -f ${PREFIX:Q}/bin/${f:Q}
	${LN} -s vim ${PREFIX:Q}/bin/${f:Q}
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
