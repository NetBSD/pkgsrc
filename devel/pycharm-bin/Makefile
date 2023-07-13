# $NetBSD: Makefile,v 1.7 2023/07/13 11:30:18 hauke Exp $


VERSION=	2019.1.2
DISTNAME=	pycharm-community-${VERSION}
PKGNAME=	pycharm-bin-${VERSION}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://download.jetbrains.com/python/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://www.jetbrains.org/
COMMENT=	JetBrain\'s python IDE
LICENSE=	apache-2.0

DEPENDS+=	intellij-fsnotifier-[0-9]*:../../sysutils/intellij-fsnotifier

WRKSRC=		${WRKDIR}/pycharm-community-${VERSION}
USE_JAVA=	yes
USE_JAVA2=	8

# 2019 breaks on java17
PKG_JVMS_ACCEPTED= openjdk11 adoptopenjdk11-bin openjdk-bin openjdk8 oracle-jdk8

USE_TOOLS+=	pax sed

REPLACE_PYTHON=	bin/printenv.py \
		bin/restart.py  \

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	pycharm-bin-${VERSION} \
			share/applications

NO_BUILD=	yes

SUBST_CLASSES+=		jdk
SUBST_STAGE.jdk=	pre-install
SUBST_MESSAGE.jdk=	Adding JVM options
SUBST_FILES.jdk=	bin/pycharm.sh
SUBST_VARS.jdk=		PKG_JAVA_HOME

do-install:
	cd ${WRKSRC} &&	\
	${RM} -r bin/fsnotifier bin/fsnotifier-arm bin/*.orig	\
	bin/fsnotifier64 bin/libdbm64.so			\
	lib/pty4j-native/linux/x86/libpty.so			\
	lib/pty4j-native/linux/x86_64/libpty.so			\
	jre64							\
	lib/pty4j-native/linux/ppc64le/libpty.so		\
	helpers/pydev/pydevd_attach_to_process/attach_linux_amd64.so \
	helpers/pydev/pydevd_attach_to_process/attach_linux_x86.so && \
	${ECHO} "idea.filewatcher.disabled=true" >> bin/idea.properties && \
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGNAME_NOREV}|g" \
	${FILESDIR}/pycharm.desktop > \
	${DESTDIR}${PREFIX}/share/applications/pycharm.desktop && \
	pax -rw -pm * ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
