# $NetBSD: Makefile,v 1.12 2023/09/11 13:47:12 ryoon Exp $
#
# TODO Import intellij-fsnotifier with inotify support from FreeBSD.

VERSION=	2023.2.1
DISTNAME=	ideaIC-${VERSION:S/.0.0//}
PKGNAME=	intellij-ce-bin-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://download.jetbrains.com/idea/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://www.jetbrains.com/idea/
COMMENT=	JetBrain's Java IDE
LICENSE=	apache-2.0

DEPENDS+=	intellij-fsnotifier-[0-9]*:../../sysutils/intellij-fsnotifier

WRKSRC=		${WRKDIR}/idea-IC-232.9559.62
USE_JAVA2=	9

USE_TOOLS+=	bash pax sed

REPLACE_PYTHON=	bin/printenv.py \
		bin/restart.py

REPLACE_BASH=	plugins/Kotlin/kotlinc/bin/kotlin	\
		plugins/Kotlin/kotlinc/bin/kotlin-dce-js\
		plugins/Kotlin/kotlinc/bin/kotlinc	\
		plugins/Kotlin/kotlinc/bin/kotlinc-js	\
		plugins/Kotlin/kotlinc/bin/kotlinc-jvm

CHECK_SHLIBS_SKIP=	*
CHECK_RELRO_SUPPORTED=	no
CHECK_PIE_SUPPORTED=	no

INSTALLATION_DIRS=	${PKGBASE} \
			share/applications

NO_BUILD=	yes

SUBST_CLASSES+=		jdk
SUBST_STAGE.jdk=	pre-configure
SUBST_FILES.jdk=	bin/idea.sh
SUBST_VARS.jdk=		PKG_JAVA_HOME

do-install:
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGBASE}|g" \
	    < ${FILESDIR}/idea.desktop \
	    > ${DESTDIR}${PREFIX}/share/applications/idea.desktop
	cd ${WRKSRC} &&	\
	${RM} -r bin/*.orig \
		bin/fsnotifier \
		bin/libdbm.so \
		bin/repair \
		lib/jna/amd64/libjnidispatch.so \
		lib/native/linux-x86_64/libsqliteij.so \
		lib/pty4j/linux/x86-64/libpty.so \
		plugins/cwm-plugin/quiche-native/win32-x86-64/*.dll \
		plugins/cwm-plugin/quiche-native/*/*.so \
		plugins/cwm-plugin/quiche-native/*/*.dylib \
		plugins/webp/lib/libwebp/linux/*.so \
		plugins/android/resources/native/*/*.so \
		plugins/android/resources/native/*/*.dylib \
		plugins/android/resources/native/*/*.dll \
		plugins/maven/lib/maven3/lib/jansi-native/Windows/*/*.dll \
		jbr && \
	cd ${WRKSRC} &&	pax -rw -pm -s ',.*\.orig,,' \
	    * ${DESTDIR}${PREFIX}/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
