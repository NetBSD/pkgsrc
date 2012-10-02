# $NetBSD: Makefile,v 1.12 2012/10/02 21:25:19 asau Exp $
#

DISTNAME=	tokyocabinet-java-1.23
PKGNAME=	java-${DISTNAME:S/-java//}
CATEGORIES=	databases
MASTER_SITES=	${HOMEPAGE:S/javadoc/javapkg/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://fallabs.com/tokyocabinet/javadoc/
COMMENT=	Java binding of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

MAKE_ENV+=	INCLUDEDIR=${BUILDLINK_PREFIX.tokyocabinet}/include

TEST_TARGET=	check

INSTALLATION_DIRS+=	share/tokyocabinet/doc/java

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/index.html \
		${DESTDIR}${PREFIX}/share/tokyocabinet/doc/java/index.html

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.29
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../mk/java-vm.mk"
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif

.include "../../mk/bsd.pkg.mk"
