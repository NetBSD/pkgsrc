# $NetBSD: Makefile,v 1.14 2001/08/06 17:44:45 pooka Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-xaw-${VIM_VERSION}

COMMENT=		Vim editor (vi clone) with X11 Athena GUI

DEPENDS+=		vim-share-${VIM_VERSION}:../vim-share
CONFLICTS+=		vim-[0-9]* vim-gtk-*

USE_X11=		yes
USE_XAW=		yes
USE_BUILDLINK_ONLY=	yes

CONFIGURE_ARGS+=	--enable-gui=athena
CONFIGURE_ARGS+=	--with-tlib=ncurses

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

.include "../../mk/bsd.prefs.mk"

.if (${XAW_TYPE} == "standard")
MAKE_ENV+=		XAW_LIB=Xaw
.else
.include "../../x11/Xaw3d/buildlink.mk"
MAKE_ENV+=		XAW_LIB=Xaw3d
.endif

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
.include "../../mk/bsd.pkg.mk"
