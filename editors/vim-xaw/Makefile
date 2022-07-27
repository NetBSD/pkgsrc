# $NetBSD: Makefile,v 1.65 2022/07/27 15:13:11 khorben Exp $

PKGNAME=		vim-xaw-${VIM_VERSION}.${VIM_PATCHLEVEL}
COMMENT=		Vim editor (vi clone) with X11 Athena GUI

.include		"../../editors/vim-share/Makefile.common"

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share
CONFLICTS+=		vim-[0-9]* vim-gtk-[0-9]* vim-gtk2-[0-9]*
CONFLICTS+=		vim-motif-[0-9]* vim-kde-[0-9]*

CONFIGURE_ARGS+=	--enable-gui=athena
CONFIGURE_ARGS+=	--with-tlib=${BUILDLINK_LIBNAME.termcap}

BUILD_TARGET=		vim
INSTALL_TARGET=		installvimbin installvimdiff installtutorbin

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		XAW_LIB="-lXaw"

post-install:
.for f in gvim.1 gview.1 rgvim.1 rgview.1
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${f}
	${LN} -s vim.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${f}
.endfor
.for f in gvim gview rgvim rgview rvim rview
	${RM} -f ${DESTDIR}${PREFIX}/bin/${f}
	${LN} -s vim ${DESTDIR}${PREFIX}/bin/${f}
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
