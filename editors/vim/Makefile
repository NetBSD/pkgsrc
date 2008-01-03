# $NetBSD: Makefile,v 1.66 2008/01/03 23:20:50 heinz Exp $

PKGNAME=		vim-${VIM_VERSION}.${VIM_PATCHLEVEL}
#PKGREVISION=		1

COMMENT=		Vim editor (vi clone) without GUI

PKG_DESTDIR_SUPPORT=	user-destdir

.include		"../../editors/vim-share/Makefile.common"

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share

CONFLICTS+=		vim-gtk-[0-9]* vim-gtk2-[0-9]* vim-motif-[0-9]*
CONFLICTS+=		vim-xaw-[0-9]* vim-kde-[0-9]*

CONFIGURE_ARGS+=	--enable-gui=no --without-x
CONFIGURE_ARGS+=	--with-tlib=ncurses

BUILD_TARGET=		vim
INSTALL_TARGET=		installvimbin
TEST_TARGET=		check

post-install:
.for f in rvim rview
	${RM} -f ${DESTDIR:Q}${PREFIX:Q}/bin/${f:Q}
	${LN} -s vim ${DESTDIR:Q}${PREFIX:Q}/bin/${f:Q}
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
