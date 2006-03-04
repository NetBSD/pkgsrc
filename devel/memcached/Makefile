# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:18 jlam Exp $
#

DISTNAME=	memcached-1.1.12
CATEGORIES=	devel
MASTER_SITES=	http://www.danga.com/memcached/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.danga.com/memcached/
COMMENT=	High-performance distributed memory object caching system

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

INSTALLATION_DIRS=	bin share/doc/${PKGBASE} man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memcached ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/memcached.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
