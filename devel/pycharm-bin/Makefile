# $NetBSD: Makefile,v 1.9 2023/08/14 05:24:15 wiz Exp $


VERSION=	2022.1.4
DISTNAME=	pycharm-community-${VERSION}
PKGNAME=	pycharm-bin-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.jetbrains.com/python/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://www.jetbrains.org/
COMMENT=	JetBrain\'s python IDE
LICENSE=	apache-2.0

DEPENDS+=	intellij-fsnotifier-[0-9]*:../../sysutils/intellij-fsnotifier

USE_JAVA2=	9

# Does not work with -17, and USE_JAVA2 is >=
# <https://intellij-support.jetbrains.com/hc/en-us/community/posts/5961640280210-Can-t-start-IntelliJ-Idea-Error-LinkageError-occurred-while-loading-main-class-com-intellij-idea-Main>
PKG_JVMS_ACCEPTED=	openjdk11 adoptopenjdk11-bin openjdk-bin

USE_TOOLS+=	pax sed

REPLACE_SH=	plugins/python-ce/helpers/typeshed/scripts/generate_proto_stubs.sh

REPLACE_PYTHON=	bin/restart.py

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	pycharm-bin-${VERSION} \
			share/applications

NO_BUILD=		yes

SUBST_CLASSES+=		jdk
SUBST_STAGE.jdk=	pre-install
SUBST_MESSAGE.jdk=	Adding JVM options
SUBST_FILES.jdk=	bin/pycharm.sh
SUBST_VARS.jdk=		PKG_JAVA_HOME

do-install:
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGNAME_NOREV}|g" \
	    ${FILESDIR}/pycharm.desktop > \
	    ${DESTDIR}${PREFIX}/share/applications/pycharm.desktop
	cd ${WRKSRC} &&	\
	${RM} -r jbr lib/pty4j-native && \
	${RM} bin/*.orig \
	      plugins/cwm-plugin/quiche-native/*/*.so \
	      plugins/python-ce/helpers/pydev/pydevd_attach_to_process/*.so \
	      bin/fsnotifier \
	      bin/libdbm64.so \
	      bin/repair && \
	${ECHO} "idea.filewatcher.disabled=true" >> bin/idea.properties && \
	pax -rw -pm * ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
