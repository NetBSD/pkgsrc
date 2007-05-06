# $NetBSD: Makefile,v 1.1.1.1 2007/05/06 12:58:36 obache Exp $
#

.include "../../databases/qdbm/Makefile.common"

PKGNAME=	java-qdbm-1.0.0.${QDBM_VERSION}
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qdbm/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://qdbm.sourceforge.net/
COMMENT=	Java API of QDBM

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
