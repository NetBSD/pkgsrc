# $NetBSD: Makefile,v 1.41 2012/10/02 21:25:55 asau Exp $
#

DISTNAME=	tokyocabinet-1.4.46
CATEGORIES=	databases
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://fallabs.com/tokyocabinet/
COMMENT=	Modern implementation of DBM
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

PKGCONFIG_OVERRIDE+=	tokyocabinet.pc.in

.include "options.mk"

TEST_TARGET=	check

.include "../../mk/pthread.buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-pthread
.else
CONFIGURE_ARGS+=	--enable-pthread
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
