# $NetBSD: Makefile,v 1.5 2003/10/14 10:12:02 salo Exp $
#

DISTNAME=	libspectrum-0.2.0.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.srcf.ucam.org/~pak21/spectrum/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.srcf.ucam.org/~pak21/spectrum/libspectrum.html
COMMENT=	ZX Spectrum emulator file format library

USE_PERL5=	build
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ENV+=		PERL=${PERL5}

DOCDIR=		${PREFIX}/share/doc/libspectrum

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/libspectrum.txt ${DOCDIR}

.include "../../devel/glib/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
