# $NetBSD: Makefile,v 1.1.1.1 2005/02/09 05:37:30 xtraeme Exp $
#

DISTNAME=	memcached-1.1.11
CATEGORIES=	databases
MASTER_SITES=	http://www.danga.com/memcached/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.danga.com/memcached/
COMMENT=	High-performance distributed memory object caching system

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

INSTALLATION_DIRS=	bin share/doc/${PKGBASE} man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memcached ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/memcached.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
