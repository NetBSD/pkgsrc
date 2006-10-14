# $NetBSD: Makefile,v 1.5 2006/10/14 01:33:50 rillig Exp $

.if (${MACHINE_ARCH} == "powerpc")
DISTNAME=		fftw-3.0.1-fma
.else
DISTNAME=		fftw-3.0.1
.endif
PKGNAME=		fftwf-3.0.1
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	fftw.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-float

DEPENDS+=		fftw>=3.0.1:../../math/fftw

.if (${MACHINE_ARCH} == "i386")
#CONFIGURE_ARGS+=	--enable-sse
CONFIGURE_ARGS+=	--with-our-malloc16
.endif
USE_LANGUAGES=		c fortran
USE_TOOLS+=		gmake

TEST_TARGET=		check

INSTALLATION_DIRS=	${PKGMANDIR}/man1

do-install:
	gmake -C ${WRKSRC} install-libLTLIBRARIES
	gmake -C ${WRKSRC} install-pkgconfigDATA
	gmake -C ${WRKSRC}/tools install-binPROGRAMS
	${INSTALL_MAN} ${WRKSRC}/tools/fftwf-wisdom.1 \
		${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
