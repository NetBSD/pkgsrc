# $NetBSD: Makefile,v 1.10 2024/05/29 16:33:50 adam Exp $

DISTNAME=	doh-0.1.20200514
PKGREVISION=	9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=curl/}
GITHUB_TAG=	2fe6faef891fa5124776eb7b7a0f618b4bf690fb

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/curl/doh/
COMMENT=	A tool for resolving host names using DNS-over-HTTPS (DoH)
LICENSE=	mit

AUTO_MKDIRS=	yes
NO_CONFIGURE=	yes

BUILD_TARGET=	${PKGBASE}
MAKE_FLAGS+=	DESTDIR="${DESTDIR}"
MAKE_FLAGS+=	BINDIR="${PREFIX}/bin"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}"

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
