# $NetBSD: Makefile,v 1.8 2006/02/05 23:10:44 joerg Exp $
#

DISTNAME=		jessie-0.9.7
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://syzygy.metastatic.org/jessie/

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.nongnu.org/jessie/
COMMENT=		GPL implementation of the Java Secure Sockets Extension

BROKEN_IN=		pkgsrc-2005Q4

DEPENDS+=		gnu-crypto>=2.0:../../security/gnu-crypto

USE_TOOLS+=		gmake
USE_JAVA2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-java-prefix=${PKG_JAVA_HOME:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/lib/java/jessie
CONFIGURE_ENV+=		JAVA=${PKG_JAVA_HOME}/bin/java
CONFIGURE_ENV+=		JAVAC=${PKG_JAVA_HOME}/bin/javac

# the list below must be only JVMs using GNU Classpath
PKG_JVMS_ACCEPTED=	kaffe

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

CLASSPATH!=		${ECHO} ${LOCALBASE}/lib/java/gnu-crypto/*.jar | ${TR} ' ' :
CONFIGURE_ENV+=		CLASSPATH=${CLASSPATH:Q}
MAKE_ENV+=		CLASSPATH=${CLASSPATH:Q}
