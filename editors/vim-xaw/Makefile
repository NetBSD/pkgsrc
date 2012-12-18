# $NetBSD: Makefile,v 1.54 2012/12/18 23:30:36 morr Exp $

PKGNAME=		vim-xaw-${VIM_VERSION}.${VIM_PATCHLEVEL}
PKGREVISION=		1
COMMENT=		Vim editor (vi clone) with X11 Athena GUI

.include		"../../editors/vim-share/Makefile.common"

DEPENDS+=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share
CONFLICTS+=		vim-[0-9]* vim-gtk-[0-9]* vim-gtk2-[0-9]*
CONFLICTS+=		vim-motif-[0-9]* vim-kde-[0-9]*

CONFIGURE_ARGS+=	--enable-gui=athena
CONFIGURE_ARGS+=	--with-tlib=${BUILDLINK_LIBNAME.termcap}

BUILD_TARGET=		vim
INSTALL_TARGET=		installvimbin

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
MAKE_ENV+=		XAW_LIB="Xaw3d"
.else
XAW_TYPE=		standard
MAKE_ENV+=		XAW_LIB="Xaw"
.endif

SUBST_CLASSES+=			fix-linking
SUBST_STAGE.fix-linking=	post-configure
SUBST_MESSAGE.fix-linking=	Fixing linking
SUBST_FILES.fix-linking=	auto/config.mk
SUBST_SED.fix-linking=		-e 's,LINK_AS_NEEDED   = .*,LINK_AS_NEEDED = no,g'

LIBS+=			-lXaw

CHECK_INTERPRETER_SKIP+=${PKGMANDIR}/man1/gvim.1 ${PKGMANDIR}/man1/gview.1
CHECK_INTERPRETER_SKIP+=${PKGMANDIR}/man1/rgvim.1 ${PKGMANDIR}/man1/rgview.1

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
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
