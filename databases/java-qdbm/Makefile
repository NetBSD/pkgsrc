# $NetBSD: Makefile,v 1.9 2022/12/15 07:12:55 wiz Exp $
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

PKG_JVMS_ACCEPTED=	kaffe openjdk8 sun-jdk7 oracle-jdk8 openjdk11

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PTHREAD=	no
TEST_TARGET=		check

.include "../../databases/qdbm/buildlink3.mk"
.include "../../mk/java-vm.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=	pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	${MY_SUBDIR:Q}/configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
