# $NetBSD: Makefile,v 1.1 2013/02/11 01:13:19 dsainty Exp $
#

DISTNAME=	rxtx-2.1-7r2
PKGNAME=	java-rxtx-2.1.7r2
CATEGORIES=	comms java
MASTER_SITES=	http://rxtx.qbang.org/pub/rxtx/
EXTRACT_SUFX=	.zip

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://rxtx.qbang.org/
COMMENT=	Java serial IO library
LICENSE=	gnu-lgpl-v2 # or later

USE_TOOLS+=	aclocal autoconf autoheader automake gmake unzip
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

# Configuration looks for certain versions of JDK - this list can be expanded
# if the patches are also appropriately updated.
PKG_JVMS_ACCEPTED= openjdk7 sun-jdk7 sun-jdk6 sun-jdk15 sun-jdk14

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME}

# The printer port support is experimental, and only supported on some
# platforms.  Disable it for consistency.
CONFIGURE_ARGS+=	--disable-PRINTER

INSTALLATION_DIRS+=	${PKG_JAVA_HOME}/jre/lib/ext
INSTALLATION_DIRS+=	${PKG_JAVA_HOME}/jre/lib/${MACHINE_ARCH}

PLIST_SUBST+=		JAVA_HOME="${PKG_JAVA_HOME:C/^${PREFIX}\///}"

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
