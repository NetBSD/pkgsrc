# $NetBSD: Makefile,v 1.54 2004/10/03 00:14:39 tv Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-${VIM_VERSION}.${VIM_PATCHLEVEL}
PKGREVISION=	1
#PKGREVISION=		1

COMMENT=		Vim editor (vi clone) without GUI

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}:../vim-share

CONFLICTS+=		vim-gtk-[0-9]* vim-gtk2-[0-9]* vim-motif-[0-9]*
CONFLICTS+=		vim-xaw-[0-9]*

CONFIGURE_ARGS+=	--enable-gui=no --without-x
CONFIGURE_ARGS+=	--with-tlib=ncurses
CONFIGURE_ARGS+=	--enable-multibyte

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

post-install:
	for f in rvim rview ; do				\
		${RM} -f ${PREFIX}/bin/$$f;			\
		${LN} -s vim ${PREFIX}/bin/$$f;			\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
