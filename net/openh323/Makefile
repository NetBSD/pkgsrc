# $NetBSD: Makefile,v 1.25 2004/10/09 16:01:23 mjl Exp $
#

DISTNAME=	openh323-v1_15_1-src
PKGNAME=	${DISTNAME:S/_/./g:S/-v/-/:S/-src//}
# PKGREVISION=	2
EXTRACT_SUFX=	-tar.gz
CATEGORIES=	net
MASTER_SITES=	http://www.voxgratia.org/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.openh323.org/
COMMENT=	Open H.323 library

MAKE_ENV+=	PWLIBDIR=${PREFIX}/share/pwlib OPENH323DIR=${WRKSRC} SYSLIBDIR=$(PREFIX)/lib
CONFIGURE_ARGS+=	PWLIBDIR=${PREFIX}

WRKSRC=		${WRKDIR}/openh323
USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	opt

post-extract:
	cd ${WRKDIR}; ${TAR} -xf ${DISTNAME:S/$/-tar/}

post-patch:
	cd ${WRKSRC}/include; ${LN} -s . openh323
	${_PKG_SILENT}cd ${WRKSRC};			\
	for f in openh323u.mak.in; do			\
		${SED} ${FILES_SUBST_SED} $$f > $$f.sed;\
		${MV} -f $$f.sed $$f;			\
	done

# override the openh323 install - it uses cp -d, and isn't libtool-aware
do-install:
	cd ${WRKSRC}/src; ${MAKE_ENV} ${GMAKE} install
	${INSTALL_DATA_DIR} ${PREFIX}/include/openh323
	cd ${WRKSRC}/include;				\
		for f in \*.h ; \
			do ${INSTALL_DATA} $$f ${PREFIX}/include/openh323; done
	cd ${WRKSRC}; ${INSTALL_DATA} version.h ${PREFIX}/include/openh323
	cd ${WRKSRC}/samples/simple; ${MAKE_ENV} ${GMAKE} install
	-${INSTALL_DATA_DIR} ${PREFIX}/share/openh323
	cd ${WRKSRC}; ${INSTALL_DATA} openh323u.mak ${PREFIX}/share/openh323
	cd ${WRKSRC}/plugins; ${GMAKE} install

.include "../../devel/pwlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
