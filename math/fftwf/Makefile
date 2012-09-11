# $NetBSD: Makefile,v 1.14 2012/09/11 23:04:19 asau Exp $

DISTNAME=	fftw-3.3.2
PKGNAME=	${DISTNAME:C/fftw/fftwf/}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ \
		http://www.fftw.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fftw.org/
COMMENT=	Collection of fast C routines to compute DFTs
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	fftw.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-float

DEPENDS+=		fftw>=3.2:../../math/fftw

.if (${MACHINE_ARCH} == "i386")
#CONFIGURE_ARGS+=	--enable-sse
CONFIGURE_ARGS+=	--with-our-malloc16
.endif
USE_LANGUAGES=		c fortran77
USE_TOOLS+=		gmake
# For the "test" target:
USE_TOOLS+=		perl

TEST_TARGET=		check

INSTALLATION_DIRS=	${PKGMANDIR}/man1
INSTALL_TARGET=		install-libLTLIBRARIES install-pkgconfigDATA

post-install:
	cd ${WRKSRC}/tools &&						\
	${SETENV} ${INSTALL_ENV} ${MAKE_ENV} 				\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS}	\
		install-binPROGRAMS
	${INSTALL_MAN} ${WRKSRC}/tools/fftwf-wisdom.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
