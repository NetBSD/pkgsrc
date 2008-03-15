# $NetBSD: Makefile,v 1.7 2008/03/15 14:18:39 joerg Exp $

.if (${MACHINE_ARCH} == "powerpc")
DISTNAME=		fftw-3.1.2-fma
.else
DISTNAME=		fftw-3.1.2
.endif
PKGNAME=		fftwf-3.1.2
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	fftw.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-float

DEPENDS+=		fftw>=3.1.2:../../math/fftw

.if (${MACHINE_ARCH} == "i386")
#CONFIGURE_ARGS+=	--enable-sse
CONFIGURE_ARGS+=	--with-our-malloc16
.endif
USE_LANGUAGES=		c fortran
USE_TOOLS+=		gmake

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
