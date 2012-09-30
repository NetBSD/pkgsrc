# $NetBSD: Makefile,v 1.46 2012/09/30 23:25:18 dholland Exp $

DISTNAME=	openh323-v1_15_2-src
PKGNAME=	openh323-1.15.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.voxgratia.org/releases/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	#http://www.h323plus.org/
#successor	http://www.openh323.org/
COMMENT=	Open H.323 library

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=			${WRKDIR}/openh323
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake tar
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	PWLIBDIR=${PREFIX:Q}

BUILD_TARGET=		opt apps
MAKE_ENV+=		PWLIBDIR=${PREFIX}/share/pwlib OPENH323DIR=${WRKSRC:Q}
MAKE_ENV+=		SYSLIBDIR=${PREFIX}/lib
INSTALL_MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX}

MAKE_JOBS_SAFE=		no

INSTALL_DIRS=		src plugins samples/simple
INSTALLATION_DIRS+=	bin include/openh323 lib share/openh323

post-patch:
	cd ${WRKSRC}/include; ${LN} -s . openh323

# override the openh323 install - it uses cp -d, and isn't libtool-aware
post-install:
	for f in ${WRKSRC}/include/*.h ; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/include/openh323; \
	done
	${INSTALL_DATA} ${WRKSRC}/version.h ${DESTDIR}${PREFIX}/include/openh323
	${INSTALL_DATA} ${WRKSRC}/openh323u.mak ${DESTDIR}${PREFIX}/share/openh323

.include "../../devel/pwlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
