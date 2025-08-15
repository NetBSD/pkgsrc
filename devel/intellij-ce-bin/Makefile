# $NetBSD: Makefile,v 1.14 2025/08/15 15:54:27 schmonz Exp $

VERSION=	2025.2
DISTNAME=	ideaIC-${VERSION:S/.0.0//}
PKGNAME=	intellij-ce-bin-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://download.jetbrains.com/idea/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://www.jetbrains.com/idea/
COMMENT=	JetBrains IntelliJ IDEA Community Edition
LICENSE=	apache-2.0

DEPENDS+=	intellij-fsnotifier-[0-9]*:../../sysutils/intellij-fsnotifier

WRKSRC=		${WRKDIR}/idea-IC-252.23892.409
USE_JAVA2=	17

USE_TOOLS+=	bash pax sed

REPLACE_BASH=		plugins/Kotlin/kotlinc/bin/kapt		\
			plugins/Kotlin/kotlinc/bin/kotlin	\
			plugins/Kotlin/kotlinc/bin/kotlinc	\
			plugins/Kotlin/kotlinc/bin/kotlinc-js	\
			plugins/Kotlin/kotlinc/bin/kotlinc-jvm	\
			plugins/terminal/shell-integrations/bash/bash-integration.bash

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

pre-configure:
	cd ${WRKSRC} &&	\
	${RM} -r bin/*.orig \
		bin/fsnotifier \
		lib/jna/amd64/libjnidispatch.so \
		lib/native/linux-x86_64/libsqliteij.so \
		lib/pty4j/linux/x86-64/libpty.so \
		plugins/cwm-plugin/quiche-native/*/*.so \
		plugins/webp/lib/libwebp/linux/*.so \
		plugins/maven/lib/maven3/lib/jansi-native/Windows/*/*.dll \
		jbr

post-configure:
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGBASE}|g" \
	    < ${FILESDIR}/idea.desktop \
	    > ${WRKDIR}/idea.desktop

do-install:
	${INSTALL_DATA} ${WRKDIR}/idea.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/
	cd ${WRKSRC} &&	pax -rw -pm -s ',.*\.orig,,' \
	    * ${DESTDIR}${PREFIX}/${PKGBASE}
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/bin/fsnotifier" \
	    > ${DESTDIR}${PREFIX}/${PKGBASE}/bin/idea.properties

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
