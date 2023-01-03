# $NetBSD: Makefile,v 1.1 2023/01/03 10:27:40 khorben Exp $

.include "../../chat/jitsi-meet/Makefile.common"

GITHUB_PROJECT=	jicofo
PKGNAME=	${GITHUB_PROJECT}-${JITSI_MEET_VERSION}

HOMEPAGE=	https://github.com/jitsi/jicofo/
COMMENT=	Server-side focus component used in Jitsi Meet conferences

DISTINFO_FILE=	${.CURDIR}/../../chat/jicofo/distinfo
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	jicofo-java-deps-${JITSI_MEET_VERSION}.tar.gz
SITES.jicofo-java-deps-${JITSI_MEET_VERSION}.tar.gz= \
		ftp://ftp.NetBSD.org/pub/NetBSD/misc/khorben/

USE_TOOLS+=	bash:run pax:build unzip

USE_JAVA2=	17

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-Duser.home=${FAKEHOMEDIR}
MAVEN_FLAGS+=	-Dmaven.repo.local=${WRKDIR}/deps
MAVEN_FLAGS+=	--offline
MAVEN_FLAGS+=	-DskipTests
MAVEN_FLAGS+=	-Dassembly.skipAssembly=false
MVN=		mvn ${MAVEN_FLAGS}

REPLACE_BASH=	resources/collect-dump-logs.sh
REPLACE_BASH+=	resources/jicofo.sh

EGDIR=			share/examples/jicofo
PKG_SYSCONFSUBDIR=	jitsi/jicofo
CONF_FILES+=		${EGDIR}/jicofo.conf \
			${PKG_SYSCONFDIR}/jicofo.conf
CONF_FILES+=		${EGDIR}/logging.properties \
			${PKG_SYSCONFDIR}/logging.properties

SUBST_CLASSES+=		java
SUBST_STAGE.java=	post-configure
SUBST_FILES.java=	resources/jicofo.sh
SUBST_SED.java=		-e 's,^exec java,exec ${JAVA_BINPREFIX}-java,'

SUBST_CLASSES+=		logging
SUBST_STAGE.logging=	post-configure
SUBST_FILES.logging=	resources/jicofo.sh
SUBST_SED.logging=	-e 's,$$SCRIPT_DIR/lib/logging\.properties,${PKG_SYSCONFDIR}/logging.properties,'

MAKE_JOBS_SAFE=		no

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${EGDIR} share/jicofo

.PHONY: create-deps-file
create-deps-file: build
	#XXX disable offline mode for maven before using this rule
	cd ${WRKSRC} && ${MVN} validate
	cd ${WRKDIR} && \
		${PAX} -wz -f jicofo-java-deps-${JITSI_MEET_VERSION}.tar.gz deps

do-configure:
	cd ${WRKSRC} && ${MVN} versions:set -DnewVersion="${JITSI_MEET_VERSION}"

do-build:
	cd ${WRKSRC} && ${MVN} package

do-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/jicofo \
		${DESTDIR}${PREFIX}/share/jicofo-${JITSI_MEET_VERSION}
	cd ${DESTDIR}${PREFIX}/share && \
		${UNZIP_CMD} ${WRKSRC}/jicofo/target/jicofo-${JITSI_MEET_VERSION}-archive.zip
	${MV} ${DESTDIR}${PREFIX}/share/jicofo-${JITSI_MEET_VERSION} \
		${DESTDIR}${PREFIX}/share/jicofo
	${LN} -sf ../share/jicofo/jicofo.sh \
		${DESTDIR}${PREFIX}/bin/jicofo
	${INSTALL_DATA} ${WRKSRC}/jicofo-selector/src/main/resources/reference.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/jicofo.conf
	${INSTALL_DATA} ${WRKSRC}/lib/logging.properties \
		${DESTDIR}${PREFIX}/${EGDIR}/logging.properties
	${INSTALL_SCRIPT} ${WRKSRC}/resources/collect-dump-logs.sh \
		${DESTDIR}${PREFIX}/share/jicofo/collect-dump-logs.sh

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
