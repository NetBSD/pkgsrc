# $NetBSD: Makefile,v 1.1.1.1 2004/03/28 20:42:08 jmmv Exp $
#

DISTNAME=	sablevm-1.1.1
CATEGORIES=	lang
MASTER_SITES=	http://devel.sablevm.org/download/1.1.1/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.sablevm.org/
COMMENT=	SableVM free Java virtual machine

DEPENDS+=	unzip>=5.50:../../archivers/unzip
DEPENDS+=	sablevm-classpath-1.1.1:../../lang/sablevm-classpath

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-signals-for-exceptions

EVAL_PREFIX+=		PREFIX.sablevm-classpath=sablevm-classpath
PREFIX.sablevm-classpath_DEFAULT=	${LOCALBASE}

pre-configure:
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${AUTOCONF}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/sablevm
	${LN} -s ${PREFIX.sablevm-classpath}/lib/sablevm-classpath \
		${PREFIX}/lib/sablevm/sablevm-classpath
	${LN} -s ${PREFIX.sablevm-classpath}/share/sablevm-classpath \
		${PREFIX}/share/sablevm/sablevm-classpath

.if !exists(/usr/include/semaphore.h)
LDFLAGS+=	-lsemaphore
BUILDLINK_TRANSFORM+=	l:rt:semaphore:
.include "../../devel/pthread-sem/buildlink3.mk"
.endif
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
