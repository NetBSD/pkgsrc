# $NetBSD: Makefile,v 1.5 2019/11/03 10:39:14 rillig Exp $
#
# TODO Import intellij-fsnotifier with inotify support from FreeBSD.

VERSION=	2019.1.2
DISTNAME=	ideaIC-${VERSION:S/.0.0//}-no-jbr
PKGNAME=	intellij-ce-bin-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://download.jetbrains.com/idea/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://www.jetbrains.org/
COMMENT=	JetBrain\'s Java IDE
LICENSE=	apache-2.0

DEPENDS+=	intellij-fsnotifier-[0-9]*:../../sysutils/intellij-fsnotifier

WRKSRC=		${WRKDIR}/idea-IC-191.7141.44
USE_JAVA=	yes
USE_JAVA2=	8

USE_TOOLS+=	bash pax sed

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
	${RM} bin/fsnotifier bin/fsnotifier-arm bin/idea.sh.orig\
	bin/fsnotifier64 bin/libdbm64.so			\
	lib/pty4j-native/linux/x86/libpty.so			\
	lib/pty4j-native/linux/x86_64/libpty.so			\
	lib/pty4j-native/linux/ppc64le/libpty.so		\
	plugins/android/lib/libwebp/linux/libwebp_jni.so	\
	plugins/android/lib/libwebp/linux/libwebp_jni64.so &&	\
	${ECHO} "idea.filewatcher.disabled=true" >> bin/idea.properties && \
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGNAME_NOREV}|g" \
	${FILESDIR}/idea.desktop > ${DESTDIR}${PREFIX}/share/applications/idea.desktop && \
	pax -rw -pm * ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
