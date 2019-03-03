# $NetBSD: Makefile,v 1.1 2019/03/03 18:02:47 youri Exp $


VERSION=	2018.3.5
DISTNAME=	pycharm-community-${VERSION}
PKGNAME=	pycharm-bin-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://download.jetbrains.com/python/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://www.jetbrains.org/
COMMENT=	JetBrain\'s python IDE
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/pycharm-community-${VERSION}
USE_JAVA=	yes
USE_JAVA2=	8

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
	${RM} -r bin/fsnotifier bin/fsnotifier-arm bin/pycharm.sh.orig\
	bin/fsnotifier64 bin/libdbm64.so			\
	lib/pty4j-native/linux/x86/libpty.so			\
	lib/pty4j-native/linux/x86_64/libpty.so jre64		\
	helpers/pydev/_pydevd_bundle/pydevd_cython_darwin_26_64.so \
	helpers/pydev/_pydevd_bundle/pydevd_cython_darwin_27_64.so \
	helpers/pydev/_pydevd_bundle/pydevd_cython_darwin_34_64.so \
	helpers/pydev/_pydevd_bundle/pydevd_cython_darwin_35_64.cpython-35m-darwin.so \
	helpers/pydev/_pydevd_bundle/pydevd_cython_darwin_36_64.cpython-36m-darwin.so \
	helpers/pydev/_pydevd_bundle/pydevd_cython_darwin_37_64.cpython-37m-darwin.so \
	helpers/pydev/_pydevd_frame_eval/pydevd_frame_evaluator_darwin_36_64.cpython-36m-darwin.so \
	helpers/pydev/_pydevd_frame_eval/pydevd_frame_evaluator_darwin_37_64.cpython-37m-darwin.so \
	helpers/pydev/pydevd_attach_to_process/attach_linux_amd64.so \
	helpers/pydev/pydevd_attach_to_process/attach_linux_x86.so && \
	${ECHO} "idea.filewatcher.disabled=true" >> bin/idea.properties && \
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGNAME}|g" \
	${FILESDIR}/pycharm.desktop > \
	${DESTDIR}${PREFIX}/share/applications/pycharm.desktop && \
	pax -rw -pm * ${DESTDIR}${PREFIX}/${PKGNAME}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
