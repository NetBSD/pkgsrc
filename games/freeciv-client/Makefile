# $NetBSD: Makefile,v 1.48 2011/11/01 06:01:15 sbd Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	5
COMMENT=	Freeciv client

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share

CONFLICTS=	freeciv-client-gtk<=1.11.4

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--disable-server

SUBST_CLASSES+=			installfix
SUBST_STAGE.installfix=		post-patch
SUBST_FILES.installfix=		common/Makefile.in
SUBST_SED.installfix+=		-e 's|^install-exec-am: install-libLTLIBRARIES|install-exec-am: \# install-libLTLIBRARIES|'
SUBST_MESSAGE.installfix=	Suppressing installation of libs already in freeciv-share.

.include "../../games/freeciv-share/Makefile.common"

.include "options.mk"

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
