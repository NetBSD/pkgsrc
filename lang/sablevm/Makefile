# $NetBSD: Makefile,v 1.29 2012/09/15 10:05:20 obache Exp $
#

DISTNAME=	sablevm-1.13
PKGREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	http://sablevm.org/download/release/1.13/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sablevm.org/
COMMENT=	SableVM free Java virtual machine

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	sablevm-classpath-1.13nb1:../../lang/sablevm-classpath

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${JAVA_HOME}
GNU_CONFIGURE_MANDIR=	${PREFIX}/${PKGMANDIR}
USE_TOOLS+=		gmake gm4 unzip:run
USE_LIBTOOL=		yes

JAVA_NAME=		sablevm
JAVA_HOME=		${PREFIX}/java/sablevm
JAVA_WRAPPERS+=		java
JAVA_WRAPPER_BIN.java=	${JAVA_HOME}/bin/java-sablevm --classpath $${CLASSPATH}

BUILDLINK_PASSTHRU_RPATHDIRS+=	${JAVA_HOME}/lib

INSTALLATION_DIRS=	java/sablevm/lib/sablevm/bin java/sablevm/lib/sablevm/jre

.if !exists(/usr/include/semaphore.h)
LDFLAGS+=	-lsemaphore
BUILDLINK_TRANSFORM+=	l:rt:semaphore
.include "../../devel/pthread-sem/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
