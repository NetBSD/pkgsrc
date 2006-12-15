# $NetBSD: Makefile,v 1.44 2006/12/15 20:32:54 joerg Exp $

PKGNAME=		vim-xaw-${VIM_VERSION}.${VIM_PATCHLEVEL}
#PKGREVISION=		1

.include "../../editors/vim-share/Makefile.common"

COMMENT=		Vim editor (vi clone) with X11 Athena GUI

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share
CONFLICTS+=		vim-[0-9]* vim-gtk-[0-9]* vim-gtk2-[0-9]*
CONFLICTS+=		vim-motif-[0-9]* vim-kde-[0-9]*

CONFIGURE_ARGS+=	--enable-gui=athena
CONFIGURE_ARGS+=	--with-tlib=ncurses

BUILD_TARGET=		vim
INSTALL_TARGET=		installvimbin

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
MAKE_ENV+=		XAW_LIB="Xaw3d"
.else
XAW_TYPE=		standard
MAKE_ENV+=		XAW_LIB="Xaw"
.endif

LIBS+=			-lXaw

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
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
