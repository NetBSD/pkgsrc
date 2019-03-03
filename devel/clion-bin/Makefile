# $NetBSD: Makefile,v 1.1 2019/03/03 17:42:40 youri Exp $


VERSION=	2018.3.4
DISTNAME=	CLion-${VERSION}
PKGNAME=	clion-bin-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://download.jetbrains.com/cpp/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://www.jetbrains.org/
COMMENT=	JetBrain\'s C/C++ IDE
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/clion-${VERSION}
USE_JAVA=	yes
USE_JAVA2=	8

USE_TOOLS+=	pax sed

REPLACE_PYTHON=	bin/printenv.py \
		bin/restart.py  \

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	clion-bin-${VERSION} \
			share/applications

NO_BUILD=	yes

SUBST_CLASSES+=		jdk
SUBST_STAGE.jdk=	pre-install
SUBST_MESSAGE.jdk=	Adding JVM options
SUBST_FILES.jdk=	bin/clion.sh
SUBST_VARS.jdk=		PKG_JAVA_HOME

REPLACE_BASH+=	bin/gdb/linux/bin/gcore

do-install:
	cd ${WRKSRC} &&	\
	${RM} -r bin/fsnotifier bin/fsnotifier-arm bin/clion.sh.orig\
	bin/fsnotifier64 bin/libdbm64.so			\
	lib/pty4j-native/linux/x86/libpty.so			\
	lib/pty4j-native/linux/x86_64/libpty.so 			\
	bin/clang bin/gdb bin/lldb jre64 bin/cmake plugins/tfsIntegration/lib/native  \
	plugins/python/helpers/pydev/pydevd_attach_to_process  \
	bin/libyjpagent-linux.so bin/libyjpagent-linux64.so && \
	${ECHO} "idea.filewatcher.disabled=true" >> bin/idea.properties && \
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGNAME}|g" \
	${FILESDIR}/clion.desktop > \
	${DESTDIR}${PREFIX}/share/applications/clion.desktop && \
	pax -rw -pm * ${DESTDIR}${PREFIX}/${PKGNAME}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
