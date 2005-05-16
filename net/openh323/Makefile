# $NetBSD: Makefile,v 1.30 2005/05/16 01:32:23 jlam Exp $

DISTNAME=	openh323-v1_15_2-src
PKGNAME=	openh323-1.15.2
CATEGORIES=	net
MASTER_SITES=	http://www.voxgratia.org/releases/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.openh323.org/
COMMENT=	Open H.323 library

WRKSRC=			${WRKDIR}/openh323
USE_GNU_TOOLS+=		make
PKGSRC_USE_TOOLS+=	tar
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	PWLIBDIR=${PREFIX}

BUILD_TARGET=		opt apps
MAKE_ENV+=		PWLIBDIR=${PREFIX}/share/pwlib OPENH323DIR=${WRKSRC}
MAKE_ENV+=		SYSLIBDIR=${PREFIX}/lib

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
	${INSTALL_DATA_DIR} ${PREFIX}/share/openh323
	cd ${WRKSRC}; ${INSTALL_DATA} openh323u.mak ${PREFIX}/share/openh323
	cd ${WRKSRC}/plugins; ${GMAKE} install

.include "../../devel/pwlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
