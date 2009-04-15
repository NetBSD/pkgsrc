# $NetBSD: Makefile,v 1.20 2009/04/15 09:07:15 mjl Exp $
#

DISTNAME=	memcached-1.2.8
# PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.danga.com/memcached/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.danga.com/memcached/
COMMENT=	High-performance distributed memory object caching system

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl
GNU_CONFIGURE=	yes

REPLACE_PERL=	scripts/memcached-tool

CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

INSTALLATION_DIRS=	bin share/doc/${PKGBASE} ${PKGMANDIR}/man1 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memcached ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/memcached.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/memcached-tool ${DESTDIR}${PREFIX}/sbin

.include "../../devel/libevent/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.0
.include "../../mk/bsd.pkg.mk"
