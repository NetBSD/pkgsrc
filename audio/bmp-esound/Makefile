# $NetBSD: Makefile,v 1.2 2004/08/31 15:47:56 jmmv Exp $
#

.include "../../audio/bmp/Makefile.common"

PKGNAME=		${DISTNAME:S/bmp/bmp-esound/}
CATEGORIES+=		gnome

DEPENDS+=		bmp>=0.9.7rc2:../../audio/bmp

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-esd/--enable-esd/}

BUILD_DIRS=		${WRKSRC}/Output/esd
INSTALL_DIRS=		${WRKSRC}/Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
