# $NetBSD: Makefile,v 1.2 2004/04/30 21:15:44 jmmv Exp $
#

DISTNAME=	sablevm-1.1.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sablevm/} \
		http://devel.sablevm.org/download/1.1.3/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.sablevm.org/
COMMENT=	SableVM free Java virtual machine

DEPENDS+=	unzip>=5.50:../../archivers/unzip
DEPENDS+=	sablevm-classpath-1.1.3:../../lang/sablevm-classpath

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

.if !exists(/usr/include/semaphore.h)
LDFLAGS+=	-lsemaphore
BUILDLINK_TRANSFORM+=	l:rt:semaphore:
.include "../../devel/pthread-sem/buildlink3.mk"
.endif
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
