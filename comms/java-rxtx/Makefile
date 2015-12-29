# $NetBSD: Makefile,v 1.9 2015/12/29 04:54:37 dholland Exp $
#

DISTNAME=	rxtx-2.1-7r2
PKGNAME=	java-rxtx-2.1.7r2
PKGREVISION=	2
CATEGORIES=	comms java
MASTER_SITES=	http://rxtx.qbang.org/pub/rxtx/
EXTRACT_SUFX=	.zip

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://rxtx.qbang.org/
COMMENT=	Java serial IO library
LICENSE=	gnu-lgpl-v2 # or later

USE_TOOLS+=	aclocal autoconf autoheader automake gmake unzip
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

PKG_DESTDIR_SUPPORT=	user-destdir

# Configuration looks for certain versions of JDK - this list can be expanded
# if the patches are also appropriately updated.
PKG_JVMS_ACCEPTED= oracle-jdk8 openjdk8 openjdk7 sun-jdk7 sun-jdk6 sun-jdk15 sun-jdk14

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
JAVA_MACHINE_ARCH=	amd64
.elif !empty(MACHINE_CPU:Marm*)
JAVA_MACHINE_ARCH=	arm
.else
JAVA_MACHINE_ARCH=	${MACHINE_ARCH}
.endif

.include "../../mk/java-vm.mk"

# Inconveniently, for built-in JRE's, PKG_JAVA_HOME will be set to the native
# directory - which we should not be messing with.  But prior to builtin.mk
# processing, PKG_JAVA_HOME will match the Pkgsrc JRE home, which is a
# suitable installation location for Native JRE, as well as being the
# correct installation location for Pkgsrc JRE.
JAVA_INSTALL_BASE:=	${PKG_JAVA_HOME}

RXTX_PATH=	${JAVA_INSTALL_BASE}/jre/lib/${JAVA_MACHINE_ARCH}
JHOME_PATH=	${JAVA_INSTALL_BASE}/jre/lib/ext

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME:Q}
MAKE_FLAGS+=	RXTX_PATH=${RXTX_PATH:Q}
MAKE_FLAGS+=	JHOME=${JHOME_PATH:Q}

INSTALLATION_DIRS+=	${RXTX_PATH:Q} ${JHOME_PATH:Q}

PLIST_SUBST+=	JAVA_MACHINE_ARCH=${JAVA_MACHINE_ARCH:Q}
PLIST_SUBST+=	JAVA_HOME="${JAVA_INSTALL_BASE:C/^${PREFIX}\///}"

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
