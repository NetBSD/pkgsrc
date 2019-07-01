# $NetBSD: Makefile,v 1.98 2019/07/01 04:08:11 ryoon Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	25
COMMENT=	Freeciv client

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share

CONFLICTS=	freeciv-client-gtk<=1.11.4

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--disable-server

.include "../../games/freeciv-share/suppress_installation.mk"

SUBST_CLASSES+=			themesonly
SUBST_STAGE.themesonly=		pre-configure
SUBST_FILES.themesonly=		data/Makefile.in
SUBST_SED.themesonly+=		-e 's|SUBDIRS = icons.*|SUBDIRS = themes|'
SUBST_SED.themesonly+=		-e 's|^	isotrident trident|DONT_SUBDIRS =|'
SUBST_SED.themesonly+=		-e 's|install-data-am: install-data-local|install-data-am: \# install-data-local|'
SUBST_MESSAGE.themesonly=	Suppressing installation of non-gui-relevant data

SUBST_CLASSES+=			themesonly2
SUBST_STAGE.themesonly2=	post-configure
SUBST_FILES.themesonly2=	data/Makefile
SUBST_SED.themesonly2+=		-e 's|SUBDIRS = icons.*|SUBDIRS = themes|'
SUBST_SED.themesonly2+=		-e 's|^	isotrident trident|DONT_SUBDIRS =|'
SUBST_MESSAGE.themesonly2=	Suppressing installation of non-gui-relevant data


.include "../../games/freeciv-share/Makefile.common"

.include "options.mk"

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
