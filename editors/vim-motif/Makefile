# $NetBSD: Makefile,v 1.45 2024/02/29 19:37:26 bsiegert Exp $

PKGNAME=		vim-motif-${VIM_VERSION}.${VIM_PATCHLEVEL}
PKGREVISION=		1

COMMENT=		Vim editor (vi clone) with X11 Motif GUI

.include		"../../editors/vim-share/Makefile.common"

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share
CONFLICTS+=		vim-[0-9]* vim-gtk2-[0-9]* vim-gtk3-[0-9]*

CONFIGURE_ARGS+=	--enable-gui=motif
CONFIGURE_ARGS+=	GUI_INC_LOC=-I${MOTIFBASE:Q}/include
CONFIGURE_ARGS+=	GUI_LIB_LOC=-L${MOTIFBASE:Q}/lib
CONFIGURE_ARGS+=	--with-tlib=${BUILDLINK_LIBNAME.termcap}

CONFIGURE_ENV+=		MOTIFBASE=${MOTIFBASE}
MAKE_ENV+=		MOTIFBASE=${MOTIFBASE}

BUILD_TARGET=		vim
INSTALL_TARGET=		installvimbin installvimdiff installtutorbin

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CHECK_INTERPRETER_SKIP+=	${PKGMANDIR}/man1/gvim.1 ${PKGMANDIR}/man1/gview.1
CHECK_INTERPRETER_SKIP+=	${PKGMANDIR}/man1/rgvim.1 ${PKGMANDIR}/man1/rgview.1

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
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
