# $NetBSD: Makefile,v 1.11 2025/03/27 19:35:54 wiz Exp $

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

PKG_JVMS_ACCEPTED=	kaffe openjdk8 openjdk11

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
