# $NetBSD: Makefile,v 1.4 2023/02/08 15:51:46 schmonz Exp $

DISTNAME=		gng-1.0.4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=gdubw/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://gng.dsun.org/
COMMENT=		Run (or create) each project's own Gradle wrapper
LICENSE=		apache-2.0

USE_LANGUAGES=		# none
USE_TOOLS+=		bash:run
NO_BUILD=		yes
REPLACE_BASH=		bin/gng
REPLACE_SH=		gradle/gradlew

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	bin/gng
SUBST_VARS.paths=	PREFIX PYTHONBIN

INSTALLATION_DIRS=	bin share/${PKGBASE}/gradle/wrapper

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gng \
		${DESTDIR}${PREFIX}/bin/gng
	${LN} -fs gng ${DESTDIR}${PREFIX}/bin/gw
	${INSTALL_DATA} ${WRKSRC}/lib/common.sh \
		${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/gradle/README.md \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/gradle
	${INSTALL_DATA} ${WRKSRC}/gradle/gng.cfg \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/gradle
	${INSTALL_SCRIPT} ${WRKSRC}/gradle/gradlew \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/gradle
	${INSTALL_DATA} ${WRKSRC}/gradle/gradlew.bat \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/gradle
	${INSTALL_DATA} ${WRKSRC}/gradle/wrapper/gradle-wrapper.jar \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/gradle/wrapper

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
