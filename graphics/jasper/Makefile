# $NetBSD: Makefile,v 1.16 2004/04/25 04:56:56 minskim Exp $
#

DISTNAME=	jasper-1.701.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ece.uvic.ca/~mdadams/jasper/software/
EXTRACT_SUFX=	.zip

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ece.uvic.ca/~mdadams/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--enable-shared --without-x --disable-opengl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jasper
.for doc in jasper jpeg2000
	${INSTALL_DATA} ${WRKSRC}/doc/${doc}.pdf ${PREFIX}/share/doc/jasper
.endfor

.include "../../mk/bsd.prefs.mk"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
