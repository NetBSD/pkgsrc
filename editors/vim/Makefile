# $NetBSD: Makefile,v 1.80 2023/09/16 12:43:13 rhialto Exp $

PKGNAME=		vim-${VIM_VERSION}.${VIM_PATCHLEVEL}

COMMENT=		Vim editor (vi clone) without GUI

.include		"../../editors/vim-share/Makefile.common"

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share

CONFLICTS+=		vim-gtk2-[0-9]* vim-gtk3-[0-9]* vim-motif-[0-9]*

CONFIGURE_ARGS+=	--enable-gui=no --without-x
CONFIGURE_ARGS+=	--with-tlib=${BUILDLINK_LIBNAME.termcap}

BUILD_TARGET=		vim
INSTALL_TARGET=		installvimbin installvimdiff installtutorbin
TEST_TARGET=		check

post-install:
.for f in rvim rview
	${RM} -f ${DESTDIR}${PREFIX}/bin/${f}
	${LN} -s vim ${DESTDIR}${PREFIX}/bin/${f}
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
