# $NetBSD: Makefile,v 1.15 2024/05/20 13:03:48 gdt Exp $
#

DISTNAME=	rxtx-2.1-7r2
PKGNAME=	java-rxtx-2.1.7r2
PKGREVISION=	3
CATEGORIES=	comms java
MASTER_SITES=	http://rxtx.qbang.org/pub/rxtx/ # https old protocol
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
PKG_JVMS_ACCEPTED=	oracle-jdk8 openjdk8 sun-jdk7

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
JNILIB=	jnilib
.else
JNILIB=	la
.endif

.include "../../mk/java-vm.mk"

RXTX_PATH=	${PREFIX}/lib/java/rxtx
JHOME_PATH=	${PREFIX}/lib/java/rxtx

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME:Q}
MAKE_FLAGS+=	RXTX_PATH=${RXTX_PATH:Q}
MAKE_FLAGS+=	JHOME=${JHOME_PATH:Q}

INSTALLATION_DIRS+=	lib/java/rxtx

PLIST_SUBST+=	JNILIB=${JNILIB}

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
