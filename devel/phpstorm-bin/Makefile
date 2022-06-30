# $NetBSD: Makefile,v 1.6 2022/06/30 11:18:17 nia Exp $


VERSION=	2018.3.4
DISTNAME=	PhpStorm-${VERSION}
PKGNAME=	phpstorm-bin-${VERSION}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://download.jetbrains.com/webide/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://www.jetbrains.org/
COMMENT=	JetBrain\'s PHP IDE
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/PhpStorm-183.5429.47
USE_JAVA=	yes
USE_JAVA2=	8

USE_TOOLS+=	pax sed

REPLACE_PYTHON=	bin/printenv.py \
		bin/restart.py  \

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	phpstorm-bin-${VERSION} \
			share/applications

NO_BUILD=	yes

SUBST_CLASSES+=		jdk
SUBST_STAGE.jdk=	pre-install
SUBST_MESSAGE.jdk=	Adding JVM options
SUBST_FILES.jdk=	bin/phpstorm.sh
SUBST_VARS.jdk=		PKG_JAVA_HOME

do-install:
	cd ${WRKSRC} &&	\
	${RM} -r bin/fsnotifier bin/fsnotifier-arm bin/phpstorm.sh.orig\
	bin/fsnotifier64 bin/libdbm64.so			\
	bin/libyjpagent-linux.so				\
	bin/libyjpagent-linux64.so				\
	plugins/performanceTesting/lib/libasyncProfiler-linux.so \
	plugins/performanceTesting/lib/libasyncProfiler-macos.so \
	lib/pty4j-native/linux/x86/libpty.so			\
	lib/pty4j-native/linux/x86_64/libpty.so jre64 &&	\
	${ECHO} "idea.filewatcher.disabled=true" >> bin/idea.properties && \
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGNAME}|g" \
	${FILESDIR}/phpstorm.desktop > \
	${DESTDIR}${PREFIX}/share/applications/phpstorm.desktop && \
	pax -rw -pm * ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
