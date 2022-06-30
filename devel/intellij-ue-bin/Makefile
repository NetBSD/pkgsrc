# $NetBSD: Makefile,v 1.7 2022/06/30 11:18:15 nia Exp $
#
# TODO Import intellij-fsnotifier with inotify support from FreeBSD.

VERSION=	2018.3.5
DISTNAME=	ideaIU-${VERSION:S/.0.0//}-no-jdk
PKGNAME=	intellij-ue-bin-${VERSION}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://download.jetbrains.com/idea/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://www.jetbrains.org/
COMMENT=	JetBrain\'s Java IDE, ultimate edition
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/idea-IU-183.5912.21
USE_JAVA=	yes
USE_JAVA2=	8

USE_TOOLS+=	pax sed

REPLACE_PYTHON=	bin/printenv.py \
		bin/restart.py  \

REPLACE_BASH=	plugins/Kotlin/kotlinc/bin/kotlin	\
		plugins/Kotlin/kotlinc/bin/kotlin-dce-js\
		plugins/Kotlin/kotlinc/bin/kotlinc	\
		plugins/Kotlin/kotlinc/bin/kotlinc-js	\
		plugins/Kotlin/kotlinc/bin/kotlinc-jvm

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	intellij-ce-bin-${VERSION} \
			share/applications

NO_BUILD=	yes

SUBST_CLASSES+=		jdk
SUBST_STAGE.jdk=	pre-install
SUBST_MESSAGE.jdk=	Adding JVM options
SUBST_FILES.jdk=	bin/idea.sh
SUBST_VARS.jdk=		PKG_JAVA_HOME

do-install:
	cd ${WRKSRC} &&	\
	${RM} -r bin/fsnotifier bin/fsnotifier-arm bin/idea.sh.orig\
	bin/fsnotifier64 bin/libdbm64.so			\
	bin/libyjpagent-linux.so bin/libyjpagent-linux64.so	\
	plugins/performanceTesting/lib/libasyncProfiler-linux.so\
	plugins/performanceTesting/lib/libasyncProfiler-macos.so\
	lib/pty4j-native/linux/x86/libpty.so			\
	lib/pty4j-native/linux/x86_64/libpty.so			\
	plugins/android/lib/libwebp/linux/libwebp_jni.so	\
	plugins/android/lib/libwebp/linux/libwebp_jni64.so 	\
	plugins/tfsIntegration/lib/native/ &&			\
	${ECHO} "idea.filewatcher.disabled=true" >> bin/idea.properties && \
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGNAME}|g" \
	${FILESDIR}/idea-ultimate.desktop > ${DESTDIR}${PREFIX}/share/applications/idea-ultimate.desktop && \
	pax -rw -pm * ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
