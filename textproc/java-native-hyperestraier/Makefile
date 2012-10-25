# $NetBSD: Makefile,v 1.2 2012/10/25 06:56:01 asau Exp $
#

.include "../../textproc/hyperestraier/Makefile.common"

PKGNAME=	java-native-hyperestraier-1.0.0.${HYPERESTRAIER_VERSION}
CATEGORIES=	databases java

COMMENT=	Java native interface of Hyper Estraier
LICENSE=	gnu-lgpl-v2.1

MY_SUBDIR=	javanative
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=	yes

TEST_TARGET=	check

.include "../../textproc/hyperestraier/buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	${MY_SUBDIR}/configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
