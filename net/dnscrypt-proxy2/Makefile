# $NetBSD: Makefile,v 1.5 2018/11/04 18:38:05 bsiegert Exp $

PKGNAME=	dnscrypt-proxy2-2.0.17
PKGREVISION=	1
DISTNAME=	dnscrypt-proxy-${PKGVERSION_NOREV}
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_GITHUB:=jedisct1/}
GITHUB_PROJECT=	dnscrypt-proxy
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/jedisct1/dnscrypt-proxy
COMMENT=	DNS proxy with support for encrypted protocols
LICENSE=	isc

EXTRACT_USING=	bsdtar
USE_TOOLS+=	pax

GO_SRCPATH=	github.com/jedisct1/dnscrypt-proxy/
GO_DIST_BASE=	${DISTNAME}

EGDIR=		${PREFIX}/share/examples/dnscrypt-proxy

RCD_SCRIPTS=	dnscrypt_proxy
CONF_FILES=	${EGDIR}/dnscrypt_proxy.toml ${PKG_SYSCONFDIR}/dnscrypt_proxy.toml

INSTALLATION_DIRS+=	${EGDIR}

do-install:
	${RUN} cd ${WRKDIR}; [ ! -d bin ] || ${PAX} -rw bin ${DESTDIR}${PREFIX}
	${INSTALL_DATA} ${FILESDIR}/dnscrypt_proxy.toml ${DESTDIR}${EGDIR}/dnscrypt_proxy.toml

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
