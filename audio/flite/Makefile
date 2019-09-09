# $NetBSD: Makefile,v 1.11 2019/09/09 09:46:38 nia Exp $
#

DISTNAME=	flite-2.1-release
PKGNAME=	${DISTNAME:S/-release//}
CATEGORIES=	audio
MASTER_SITES=	http://www.festvox.org/flite/packed/flite-2.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.festvox.org/flite/
COMMENT=	Lightweight text to speech synthesis engine

# Error opening output file '[...]/cmu_us_kal_diphone.o': No such file or directory
MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS+=	bin include/flite lib share/doc/flite

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/flite ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/flite_cmu* ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/flite_time ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/build/platform/lib/libflite* ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include/flite
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/flite

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
