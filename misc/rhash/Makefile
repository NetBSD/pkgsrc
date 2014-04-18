# $NetBSD: Makefile,v 1.1 2014/04/18 21:21:30 wiz Exp $

DISTNAME=	rhash-1.3.1
CATEGORIES=	security
MASTER_SITES=	-https://github.com/rhash/RHash/archive/v1.3.1.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rhash/RHash
COMMENT=	Calculate/check CRC32, MD5, SHA1, GOST, TTH, BTIH or other hash sums
LICENSE=	mit

WRKSRC=                 ${WRKDIR}/${DISTNAME:S/rh/RH/}
INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/examples/rhash

CONF_FILES+=		${PREFIX}/share/examples/rhash/rhashrc ${PKG_SYSCONFDIR}/rhashrc

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} rhash ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_LIB} librhash/librhash.a ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_DATA} librhash/rhash.h librhash/rhash_timing.h ${DESTDIR}${PREFIX}/include && \
	${INSTALL_DATA} dist/rhash.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
	${INSTALL_DATA} dist/rhashrc.sample ${DESTDIR}${PREFIX}/share/examples/rhash/rhashrc

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
