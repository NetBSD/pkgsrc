# $NetBSD: Makefile,v 1.35 2024/06/07 15:33:17 abs Exp $

DISTNAME=	unifi-8.2.93
CATEGORIES=	net
MASTER_SITES=	-http://dl.ubnt.com/unifi/${PKGVERSION_NOREV}/UniFi.unix.zip
EXTRACT_SUFX=	.zip

# Updates must be tested to not only build but actually function under
# at least NetBSD 10/amd64 with actual UBNT hardware.
MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.ubnt.com/download/unifi/
# The content that belongs in NEWS are often in a blog.
#BLOGPAGE=	https://community.ui.com/releases
COMMENT=	Provisioning software for network products made by Ubiquiti
LICENSE=	ubiquiti-license

# Bundled firmware images cannot be redistributed
RESTRICTED=		No permission to redistribute
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

DISTFILES=		${DEFAULT_DISTFILES}
EXTRACT_ONLY=		${DEFAULT_DISTFILES}


# Unifi bundles snappy-java-1.0.5.jar, which contains native code.
# We can use the bundled snappy-java but we must recompile the native portion
# because it only ship linux binaries. The rcd script takes care of loading the
# correct library.
SNAPPY_JAVA=		snappy-java-1.0.5.4
# github.mk only works for the main MASTER_SITES definition and does
# not support SITES
SITES.${SNAPPY_JAVA}.tar.gz=	-https://github.com/xerial/snappy-java/archive/${SNAPPY_JAVA:S/snappy-java-//}.tar.gz
DISTFILES+=		${SNAPPY_JAVA}.tar.gz
EXTRACT_ONLY+=		${SNAPPY_JAVA}.tar.gz

SNAPPY=			snappy-1.0.5
SITES.${SNAPPY}.tar.gz=	http://download.openpkg.org/components/cache/snappy/ \
			https://ftp.NetBSD.org/pub/pkgsrc/distfiles/snappy-java/
DISTFILES+=		${SNAPPY}.tar.gz
EXTRACT_ONLY+=		${SNAPPY}.tar.gz

CHECK_SHLIBS_SKIP=	unifi/lib/native/*
INSTALLATION_DIRS=	unifi share/doc/unifi

# Emulated JDK doesn't work due to epoll issues.  Also, would require
# matching emulated native libraries, and we only compile actual
# native libaries.
PKG_JVMS_ACCEPTED=	openjdk17
PKGSRC_MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME}
USE_LANGUAGES=		c c++	# for snappy JNI library
USE_TOOLS+=		gmake pax
WRKSRC=			${WRKDIR}

.include "options.mk"

FILES_SUBST+=		UNIFI_USER=${UNIFI_USER:Q} UNIFI_GROUP=${UNIFI_GROUP:Q}
FILES_SUBST+=		JAVA=${PKG_JAVA_HOME}/bin/java
RCD_SCRIPTS=		unifi
UNIFI_USER?=		unifi
UNIFI_GROUP?=		unifi
PKG_USERS_VARS=		UNIFI_USER
PKG_GROUPS_VARS=	UNIFI_GROUP
PKG_GROUPS=		${UNIFI_GROUP}
PKG_USERS=		${UNIFI_USER}:${UNIFI_GROUP}

.for d in data logs run work
OWN_DIRS_PERMS+=	${PREFIX}/unifi/${d} ${UNIFI_USER} ${UNIFI_GROUP} 0700
.endfor

.include "../../mk/bsd.prefs.mk"

post-extract:
# drop executable bit
	find ${WRKSRC}/UniFi -type f -print0 | xargs -0 chmod -x
	mkdir ${WRKDIR}/${SNAPPY_JAVA}/target
	ln -s ${WRKDIR}/${SNAPPY} ${WRKDIR}/${SNAPPY_JAVA}/target
# drop platform specific binaries
# as far as we know, these are for cloud access to your controller
	ls -R ${WRKDIR}/UniFi/lib/native
	rm -rf ${WRKDIR}/UniFi/lib/native/Windows
.if ${OPSYS} != "Linux"
	rm -rf ${WRKDIR}/UniFi/lib/native/Linux
.else
.  if ${MACHINE_ARCH} != "aarch64"
	rm -rf ${WRKDIR}/UniFi/lib/native/Linux/aarch64
.  endif
.  if ${MACHINE_ARCH} != "earmv7"
	rm -rf ${WRKDIR}/UniFi/lib/native/Linux/armv7
.  endif
.  if ${MACHINE_ARCH} != "x86_64"
	rm -rf ${WRKDIR}/UniFi/lib/native/Linux/x86_64
.  endif
.endif
.if ${OPSYS} != "Darwin"
	rm -rf ${WRKDIR}/UniFi/lib/native/Mac
.else
.  if ${MACHINE_ARCH} != "x86_64"
	rm -rf ${WRKDIR}/UniFi/lib/native/Mac/x86_64
.  endif
.endif

do-build:
# bundled mongod is a linux binary; replace with symlink to native binary
	rm -f ${WRKSRC}/UniFi/bin/mongod
	ln -s ${PREFIX}/bin/mongod ${WRKSRC}/UniFi/bin/mongod
	cd ${WRKDIR}/${SNAPPY_JAVA} && ${BUILD_MAKE_CMD} native

do-install:
	cd ${WRKSRC}/UniFi && pax -rw . ${DESTDIR}${PREFIX}/unifi
	${INSTALL_LIB} ${WRKDIR}/${SNAPPY_JAVA}/target/snappy-1.0.5-Default/libsnappyjava.so ${DESTDIR}${PREFIX}/unifi/lib
	${INSTALL_DATA} ${FILESDIR}/README.mongodb ${DESTDIR}${PREFIX}/share/doc/unifi

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
