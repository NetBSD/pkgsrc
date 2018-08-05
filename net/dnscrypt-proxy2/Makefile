# $NetBSD: Makefile,v 1.2 2018/08/05 12:28:06 nia Exp $

PKGNAME=	dnscrypt-proxy2-2.0.16
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

do-install:
	${RUN} cd ${WRKDIR}; [ ! -d bin ] || ${PAX} -rw bin ${DESTDIR}${PREFIX}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
