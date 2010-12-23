# $NetBSD: Makefile,v 1.32 2010/12/23 11:44:40 dsainty Exp $

DISTNAME=	jasper-1.900.1
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.ece.uvic.ca/~mdadams/jasper/software/
EXTRACT_SUFX=	.zip

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ece.uvic.ca/~mdadams/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --without-x --disable-opengl

INSTALLATION_DIRS+=	share/doc/jasper

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/jasper.pdf ${DESTDIR}${PREFIX}/share/doc/jasper
	${INSTALL_DATA} ${WRKSRC}/doc/jpeg2000.pdf ${DESTDIR}${PREFIX}/share/doc/jasper

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
