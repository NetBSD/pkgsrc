# $NetBSD: Makefile,v 1.30 2008/02/11 10:12:24 drochner Exp $

DISTNAME=	SDL_image-1.2.6
PKGREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_image/
COMMENT=	Load images as SDL surfaces

CONFLICTS=		SDL-image-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-tif

INSTALLATION_DIRS=	bin

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/showimage \
		${DESTDIR:Q}${PREFIX:Q}/bin

BUILDLINK_API_DEPENDS.SDL+=	SDL>=1.2.10
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
