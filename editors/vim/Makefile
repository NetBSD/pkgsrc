# $NetBSD: Makefile,v 1.42 2002/03/24 19:38:25 martti Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-${VIM_VERSION}.${VIM_PATCHLEVEL}

COMMENT=		Vim editor (vi clone) without gui

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}:../vim-share

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
