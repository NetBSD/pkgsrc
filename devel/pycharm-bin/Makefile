# $NetBSD: Makefile,v 1.10 2023/09/11 13:48:19 ryoon Exp $


VERSION=	2023.2.1
DISTNAME=	pycharm-community-${VERSION}
PKGNAME=	pycharm-bin-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://download.jetbrains.com/python/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://www.jetbrains.org/
COMMENT=	JetBrain\'s python IDE
LICENSE=	apache-2.0

DEPENDS+=	intellij-fsnotifier-[0-9]*:../../sysutils/intellij-fsnotifier

USE_JAVA2=	9

PKG_JVMS_ACCEPTED=	openjdk17 oracle-jdk17
PKG_JVMS_ACCEPTED+=	openjdk11 adoptopenjdk11-bin openjdk-bin

USE_TOOLS+=	pax sed

REPLACE_SH=	plugins/python-ce/helpers/typeshed/scripts/generate_proto_stubs.sh
REPLACE_SH+=	plugins/python-ce/helpers/pydev/pydevd_attach_to_process/linux_and_mac/compile_*.sh

REPLACE_PYTHON=	bin/restart.py

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	${PKGBASE} \
			share/applications

NO_BUILD=		yes

SUBST_CLASSES+=		jdk
SUBST_STAGE.jdk=	pre-install
SUBST_MESSAGE.jdk=	Adding JVM options
SUBST_FILES.jdk=	bin/pycharm.sh
SUBST_VARS.jdk=		PKG_JAVA_HOME

do-install:
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGBASE}|g" \
	    ${FILESDIR}/pycharm.desktop > \
	    ${DESTDIR}${PREFIX}/share/applications/pycharm.desktop
	cd ${WRKSRC} &&	\
	${RM} -rf bin/*.orig \
		bin/fsnotifier \
		bin/libdbm.so \
		bin/repair \
		lib/jna/amd64/libjnidispatch.so \
		lib/native/linux-x86_64/libsqliteij.so \
		lib/pty4j/linux/x86-64/libpty.so \
		plugins/python-ce/helpers/pydev/pydevd_attach_to_process/*.so \
		plugins/python-ce/helpers/pydev/_pydevd_frame_eval/*.so \
		plugins/python-ce/helpers/pydev/_pydevd_bundle/*.so \
		plugins/python-ce/helpers/coveragepy_old/coverage/*.so \
		plugins/cwm-plugin/quiche-native/win32-x86-64/*.dll \
		plugins/cwm-plugin/quiche-native/*/*.so \
		plugins/cwm-plugin/quiche-native/*/*.dylib \
		jbr && \
	${ECHO} "idea.filewatcher.disabled=true" >> bin/idea.properties && \
	pax -rw -pm * ${DESTDIR}${PREFIX}/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
