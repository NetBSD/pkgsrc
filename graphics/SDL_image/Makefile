# $NetBSD: Makefile,v 1.14 2004/02/03 01:27:37 xtraeme Exp $
#

DISTNAME=		SDL_image-1.2.3
PKGREVISION=		1
CATEGORIES=		graphics devel
MASTER_SITES=		http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.libsdl.org/projects/SDL_image/
COMMENT=		Load images as SDL surfaces

CONFLICTS=		SDL-image-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-tif

INSTALLATION_DIRS=	bin

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/showimage \
		${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
PLIST_SUBST+=		AVAILABLE="@comment "
.else
PLIST_SUBST+=		AVAILABLE=
.endif

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
