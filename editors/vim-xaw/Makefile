# $NetBSD: Makefile,v 1.21 2002/03/24 19:39:19 martti Exp $

.include		"../vim-share/Makefile.common"

PKGNAME=		vim-xaw-${VIM_VERSION}.${VIM_PATCHLEVEL}

COMMENT=		Vim editor (vi clone) with X11 Athena GUI

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}:../vim-share
CONFLICTS+=		vim-[0-9]* vim-gtk-[0-9]*

USE_BUILDLINK_ONLY=	yes
CONFIGURE_ARGS+=	--enable-gui=athena
CONFIGURE_ARGS+=	--with-tlib=ncurses

ALL_TARGET=		vim
INSTALL_TARGET=		installvimbin

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
MAKE_ENV+=		XAW_LIB="Xaw3d" 
.else
XAW_TYPE=		standard
MAKE_ENV+=		XAW_LIB="Xaw" 
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
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/xaw.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
