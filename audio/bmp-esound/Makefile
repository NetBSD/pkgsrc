# $NetBSD: Makefile,v 1.1.1.1 2004/04/11 18:13:11 jmmv Exp $
#

.include "../../audio/bmp/Makefile.common"

PKGNAME=		${DISTNAME:S/bmp/bmp-esound/}
CATEGORIES+=		gnome

DEPENDS+=		bmp>=0.9.6:../../audio/bmp

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-esd/--enable-esd/}

BUILD_DIRS=		${WRKSRC}/Output/esd
INSTALL_DIRS=		${WRKSRC}/Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
