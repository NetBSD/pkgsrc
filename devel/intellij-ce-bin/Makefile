# $NetBSD: Makefile,v 1.10 2022/06/30 11:18:15 nia Exp $
#
# TODO Import intellij-fsnotifier with inotify support from FreeBSD.

VERSION=	2021.3.2
DISTNAME=	ideaIC-${VERSION:S/.0.0//}-no-jbr
PKGNAME=	intellij-ce-bin-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://download.jetbrains.com/idea/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://www.jetbrains.com/idea/
COMMENT=	JetBrain's Java IDE
LICENSE=	apache-2.0

DEPENDS+=	intellij-fsnotifier-[0-9]*:../../sysutils/intellij-fsnotifier

WRKSRC=		${WRKDIR}/idea-IC-213.6777.52
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

INSTALLATION_DIRS=	${PKGNAME_NOREV} \
			share/applications

NO_BUILD=	yes

SUBST_CLASSES+=		jdk
SUBST_STAGE.jdk=	pre-configure
SUBST_FILES.jdk=	bin/idea.sh
SUBST_VARS.jdk=		PKG_JAVA_HOME

do-install:
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGNAME_NOREV}|g" \
	    < ${FILESDIR}/idea.desktop \
	    > ${DESTDIR}${PREFIX}/share/applications/idea.desktop
	cd ${WRKSRC} &&	pax -rw -pm -s ',.*\.orig,,' \
	    * ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}

.include "../../lang/python/application.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
