# $NetBSD: Makefile,v 1.13 2007/08/30 19:33:55 joerg Exp $
#

DISTNAME=	memcached-1.2.2
CATEGORIES=	devel
MASTER_SITES=	http://www.danga.com/memcached/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.danga.com/memcached/
COMMENT=	High-performance distributed memory object caching system

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

INSTALLATION_DIRS=	bin share/doc/${PKGBASE} ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memcached ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/memcached.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
