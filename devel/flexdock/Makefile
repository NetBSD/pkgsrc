# $NetBSD: Makefile,v 1.1.1.1 2010/03/08 12:38:39 dmcmahill Exp $
#

DISTNAME=	flexdock-0.5.1
CATEGORIES=	devel
MASTER_SITES=	https://flexdock.dev.java.net/files/documents/2037/52479
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flexdock.dev.java.net/
COMMENT=	Swing windowing and docking framework
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_JAVA=	run

INSTALLATION_DIRS=	\
	lib/java/flexdock \
	lib/java/flexdock/lib \
	lib/java/flexdock/lib/jmf \
	lib/java/flexdock/lib/jmf/doc \
	lib/java/flexdock/lib/jmf/lib \
	share/examples/flexdock

PLIST_SUBST+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}

do-build:
	${MKDIR} ${WRKSRC}
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/lib/java/flexdock/flexdock-demo-${PKGVERSION_NOREV}.jar \"\$$@\"\\n" > ${WRKDIR}/flexdock.sh

FD_FILES=	\
	flexdock-demo-0.5.1.jar \
	flexdock-0.5.1.jar \
	lib/jmf/doc/readme.html \
	lib/jmf/lib/customizer.jar \
	lib/jmf/lib/jmf.jar \
	lib/jmf/lib/jmf.properties \
	lib/jmf/lib/mediaplayer.jar \
	lib/jmf/lib/multiplayer.jar \
	lib/LICENSE.txt \
	lib/commons-logging-1.1.jar \
	lib/looks-2.1.1.jar \
	lib/skinlf.jar

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/flexdock.sh ${DESTDIR}${PREFIX}/share/examples/flexdock/
.for tmp in ${FD_FILES}
	${INSTALL_DATA} ${WRKDIR}/${tmp}  ${DESTDIR}${PREFIX}/lib/java/flexdock/${tmp}
.endfor

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
