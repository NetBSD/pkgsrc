# $NetBSD: Makefile,v 1.7 2019/07/11 09:25:24 nia Exp $
#

.include "../../databases/qdbm/Makefile.common"

PKGNAME=	java-qdbm-1.0.0.${QDBM_VERSION}
CATEGORIES=	databases java

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fallabs.com/qdbm/jspex.html
COMMENT=	Java API of QDBM
LICENSE=	gnu-lgpl-v2.1

MY_SUBDIR=	java
BUILD_DIRS=	${MY_SUBDIR:Q}
CONFIGURE_DIRS=	${MY_SUBDIR:Q}

GNU_CONFIGURE=	yes
TEST_TARGET=	check

.include "../../databases/qdbm/buildlink3.mk"
.include "../../mk/java-vm.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=	pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	${MY_SUBDIR:Q}/configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
