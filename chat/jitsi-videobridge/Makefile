# $NetBSD: Makefile,v 1.6 2025/08/26 22:15:45 gdt Exp $

.include "../../chat/jitsi-meet/Makefile.common"

GITHUB_PROJECT=	jitsi-videobridge
PKGNAME=	${GITHUB_PROJECT}-${JITSI_MEET_VERSION}

HOMEPAGE=	https://github.com/jitsi/jitsi-videobridge/
COMMENT=	WebRTC compatible video router or SFU

# The jitsi-videobridge repo distributes files with the same name as
# the jitsi-meet repo, but with different contents.
DIST_SUBDIR=	jitsi-videobridge
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	jitsi-videobridge-java-deps-${JITSI_MEET_VERSION}.tar.gz
SITES.jitsi-videobridge-java-deps-${JITSI_MEET_VERSION}.tar.gz= \
		ftp://ftp.NetBSD.org/pub/NetBSD/misc/ktnb/

DEPENDS+=	jitsi-srtp-[0-9]*:../../chat/jitsi-srtp

USE_TOOLS+=	bash:run pax:build unzip

USE_JAVA2=	17

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

MAVEN_FLAGS+=	-Duser.home=${FAKEHOMEDIR}
MAVEN_FLAGS+=	-Dmaven.repo.local=${WRKDIR}/deps
MAVEN_FLAGS+=	--offline
MAVEN_FLAGS+=	-PbuildFatJar
MAVEN_FLAGS+=	-DskipTests
MAVEN_FLAGS+=	-Dassembly.skipAssembly=false
MVN=		${PKGSRC_SETENV} ${MAKE_ENV} mvn ${MAVEN_FLAGS}

REPLACE_BASH=	jvb/resources/jvb.sh
REPLACE_BASH+=	resources/collect-dump-logs.sh
REPLACE_BASH+=	resources/graceful_shutdown.sh

EGDIR=			share/examples/jitsi-videobridge
PKG_SYSCONFSUBDIR=	jitsi/videobridge
CONF_FILES+=		${EGDIR}/jvb.conf \
			${PKG_SYSCONFDIR}/jvb.conf
CONF_FILES+=		${EGDIR}/logging.properties \
			${PKG_SYSCONFDIR}/logging.properties
CONF_FILES+=		${EGDIR}/sip-communicator.properties \
			${PKG_SYSCONFDIR}/sip-communicator.properties
CONF_FILES+=		${EGDIR}/videobridge.rc \
			${PKG_SYSCONFDIR}/videobridge.rc

SUBST_CLASSES+=		java
SUBST_STAGE.java=	post-configure
SUBST_FILES.java=	jvb/resources/jvb.sh
SUBST_SED.java=		-e 's,^exec java,exec ${JAVA_BINPREFIX}-java,'

SUBST_CLASSES+=		logging
SUBST_STAGE.logging=	post-configure
SUBST_FILES.logging=	jvb/resources/jvb.sh
SUBST_SED.logging=	-e 's,$$SCRIPT_DIR/lib/logging\.properties,${PKG_SYSCONFDIR}/logging.properties,'

SUBST_CLASSES+=		rc
SUBST_STAGE.rc=		post-configure
SUBST_FILES.rc=		jvb/resources/jvb.sh
SUBST_SED.rc=		-e 's,$$SCRIPT_DIR/lib/videobridge\.rc,${PKG_SYSCONFDIR}/videobridge.rc,'

# \todo Document why and file bug upstream.
MAKE_JOBS_SAFE=		no

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${EGDIR} share/jitsi-videobridge

# When updating, it is necessary to create a tarball of the java
# dependencies, because the java/maven approach is to download them at
# build time.  This rule does a build, and then tars up the deps.  The
# next step is to place that tarball somewhere and update the
# DISTFILES statement above.  Note that the pkgsrc version is encoded
# in the file, so if this results in PKGREVISION++ (e.g. because the
# deps file changed), or if it's a new upstream version, the version
# must be bumped *before* creating the deps file.
#
# \todo maven should have support for declaring offline by default, and a
# way for rules like this to omit that.
# 
# NB: Comment out "MAVEN_FLAGS+= --offline" above to allow downloading
# when running this target.
#
.PHONY: create-deps-file
create-deps-file: build
	cd ${WRKSRC} && ${MVN} validate
	cd ${WRKDIR} && \
		${PAX} -wz -f jitsi-videobridge-java-deps-${JITSI_MEET_VERSION}.tar.gz deps

do-configure:
	cd ${WRKSRC} && ${MVN} versions:set -DnewVersion="${JITSI_MEET_VERSION}"

do-build:
	cd ${WRKSRC} && ${MVN} package

do-install:
	${INSTALL_DATA} ${WRKSRC}/jvb/target/jitsi-videobridge-${JITSI_MEET_VERSION}-jar-with-dependencies.jar \
		${DESTDIR}${PREFIX}/share/jitsi-videobridge/jitsi-videobridge.jar
	${LN} -sf ../share/jitsi-videobridge/jvb.sh \
		${DESTDIR}${PREFIX}/bin/jvb
	${INSTALL_DATA} ${WRKSRC}/jvb/src/main/resources/reference.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/jvb.conf
	${INSTALL_DATA} ${WRKSRC}/jvb/lib/logging.properties \
		${DESTDIR}${PREFIX}/${EGDIR}/logging.properties
	${INSTALL_DATA} ${FILESDIR}/sip-communicator.properties \
		${DESTDIR}${PREFIX}/${EGDIR}/sip-communicator.properties
	${INSTALL_DATA} ${WRKSRC}/jvb/lib/videobridge.rc \
		${DESTDIR}${PREFIX}/${EGDIR}/videobridge.rc
	${INSTALL_SCRIPT} ${WRKSRC}/resources/collect-dump-logs.sh \
		${DESTDIR}${PREFIX}/share/jitsi-videobridge/collect-dump-logs.sh
	${INSTALL_SCRIPT} ${WRKSRC}/resources/graceful_shutdown.sh \
		${DESTDIR}${PREFIX}/share/jitsi-videobridge/graceful_shutdown.sh
	${INSTALL_DATA} ${WRKSRC}/jvb/resources/jvb.bat \
		${DESTDIR}${PREFIX}/share/jitsi-videobridge/jvb.bat
	${INSTALL_SCRIPT} ${WRKSRC}/jvb/resources/jvb.sh \
		${DESTDIR}${PREFIX}/share/jitsi-videobridge/jvb.sh

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
