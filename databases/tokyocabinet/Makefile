# $NetBSD: Makefile,v 1.47 2022/01/06 13:53:40 taca Exp $
#

DISTNAME=	tokyocabinet-1.4.48
CATEGORIES=	databases
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dbmx.net/tokyocabinet/index.html
COMMENT=	Modern implementation of DBM
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_GCC_RUNTIME=	yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c99

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
