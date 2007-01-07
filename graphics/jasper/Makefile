# $NetBSD: Makefile,v 1.24 2007/01/07 19:02:12 adam Exp $

DISTNAME=	jasper-1.900.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ece.uvic.ca/~mdadams/jasper/software/
EXTRACT_SUFX=	.zip

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ece.uvic.ca/~mdadams/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --without-x --disable-opengl

INSTALLATION_DIRS+=	share/doc/jasper

post-install:
.for doc in jasper jpeg2000
	${INSTALL_DATA} ${WRKSRC}/doc/${doc}.pdf ${PREFIX}/share/doc/jasper
.endfor

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
