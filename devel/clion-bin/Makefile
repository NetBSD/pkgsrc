# $NetBSD: Makefile,v 1.6 2022/06/30 11:18:11 nia Exp $

VERSION=	2021.2
DISTNAME=	CLion-${VERSION}
PKGNAME=	clion-bin-${VERSION}
PKGREVISION=	1
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

REPLACE_PYTHON+=	bin/printenv.py
REPLACE_PYTHON+=	bin/restart.py

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
	${RM} -r \
	bin/clang \
	bin/clion.sh.orig \
	bin/fsnotifier \
	bin/cmake \
	bin/gdb \
	bin/libdbm64.so \
	lib/pty4j-native/ \
	plugins/python-ce \
	plugins/performanceTesting \
	plugins/cwm-plugin \
	jbr/lib \
	jbr/bin \
	bin/lldb && \
	${ECHO} "idea.filewatcher.disabled=true" >> bin/idea.properties && \
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGNAME}|g" \
	${FILESDIR}/clion.desktop > \
	${DESTDIR}${PREFIX}/share/applications/clion.desktop && \
	pax -rw -pm * ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
