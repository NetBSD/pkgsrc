# $NetBSD: Makefile,v 1.3 2003/10/02 15:08:05 adam Exp $

DISTNAME=	libspectrum-0.2.0.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.srcf.ucam.org/~pak21/spectrum/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.srcf.ucam.org/~pak21/spectrum/libspectrum.html
COMMENT=	ZX Spectrum emulator file format library

USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
LIBTOOL_OVERRIDE=${WRKSRC}/libtool

DOCDIR=		${PREFIX}/share/doc/libspectrum

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/libspectrum.txt ${DOCDIR}

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
