# $NetBSD: Makefile,v 1.25 2007/05/18 23:55:53 heinz Exp $

PKGNAME=		vim-motif-${VIM_VERSION}.${VIM_PATCHLEVEL}
#PKGREVISION=		1

COMMENT=		Vim editor (vi clone) with X11 Motif GUI

PKG_DESTDIR_SUPPORT=	user-destdir

.include		"../../editors/vim-share/Makefile.common"

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share
CONFLICTS+=		vim-[0-9]* vim-gtk-[0-9]* vim-gtk2-[0-9]*
CONFLICTS+=		vim-xaw-[0-9]* vim-kde-[0-9]*

CONFIGURE_ARGS+=	--enable-gui=motif
CONFIGURE_ARGS+=	--with-tlib=ncurses

CONFIGURE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR:Q}
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR:Q}

BUILD_TARGET=		vim
INSTALL_TARGET=		installvimbin

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CHECK_INTERPRETER_SKIP+=${PKGMANDIR}/man1/gvim.1 ${PKGMANDIR}/man1/gview.1
CHECK_INTERPRETER_SKIP+=${PKGMANDIR}/man1/rgvim.1 ${PKGMANDIR}/man1/rgview.1

post-install:
.for f in gvim.1 gview.1 rgvim.1 rgview.1
	${RM} -f ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1/${f:Q}
	${LN} -s vim.1 ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1/${f:Q}
.endfor
.for f in gvim gview rgvim rgview rvim rview
	${RM} -f ${DESTDIR:Q}${PREFIX:Q}/bin/${f:Q}
	${LN} -s vim ${DESTDIR:Q}${PREFIX:Q}/bin/${f:Q}
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
