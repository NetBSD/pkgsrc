# $NetBSD: Makefile,v 1.23 2024/04/05 18:14:46 ktnb Exp $

DISTNAME=	gradle-8.7-bin
PKGNAME=	${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	https://services.gradle.org/distributions/
EXTRACT_SUFX=	.zip

MAINTAINER=	asiekierka@gmail.com
HOMEPAGE=	https://gradle.org/
COMMENT=	Groovy-based Java build system
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME:S/-bin//}

USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	bash:run pax:build
NO_BUILD=	yes

pre-configure:
	${CP} ${FILESDIR}/gradle-launcher ${WRKSRC}/gradle-launcher

REPLACE_BASH+=		gradle-launcher

SUBST_CLASSES+=		launcher
SUBST_FILES.launcher=	gradle-launcher
SUBST_STAGE.launcher=	post-configure
SUBST_SED.launcher=	-e 's,@APP_HOME@,${PREFIX}/lib/java/gradle,g'
SUBST_VARS.launcher=	PREFIX
SUBST_SED.launcher+=	-e 's,@APP_LAUNCHER@,lib/gradle-launcher-${PKGVERSION_NOREV}\.jar,g'
SUBST_SED.launcher+=	-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'

INSTALLATION_DIRS=	bin lib/java/gradle/lib lib/java/gradle/lib/plugins

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gradle-launcher ${DESTDIR}${PREFIX}/bin/gradle
	cd ${WRKSRC}/lib && ${PAX} -wr * ${DESTDIR}${PREFIX}/lib/java/gradle/lib

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
