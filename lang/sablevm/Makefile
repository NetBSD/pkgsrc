# $NetBSD: Makefile,v 1.5 2004/10/03 00:15:02 tv Exp $
#

DISTNAME=	sablevm-1.1.3
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sablevm/} \
		http://devel.sablevm.org/download/1.1.3/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.sablevm.org/
COMMENT=	SableVM free Java virtual machine

DEPENDS+=	unzip>=5.50:../../archivers/unzip
DEPENDS+=	sablevm-classpath-1.1.3nb1:../../lang/sablevm-classpath

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${JAVA_HOME}
NO_MTREE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

JAVA_NAME=		sablevm
JAVA_HOME=		${PREFIX}/java/sablevm
JAVA_WRAPPERS=		java
JAVA_WRAPPER_BIN.java=	${JAVA_HOME}/bin/sablevm

PRINT_PLIST_AWK+=	/^@dirrm java\/sablevm$$/ \
				{ print "@comment in sablevm-classpath: " $$0; \
				  next; }

BUILDLINK_PASSTHRU_RPATHDIRS+=	${JAVA_HOME}/lib

.if !exists(/usr/include/semaphore.h)
LDFLAGS+=	-lsemaphore
BUILDLINK_TRANSFORM+=	l:rt:semaphore
.include "../../devel/pthread-sem/buildlink3.mk"
.endif
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
