# $NetBSD: Makefile,v 1.13 2024/05/29 16:33:48 adam Exp $

GITHUB_PROJECT=	bbk
GITHUB_TAG=	7b810a696c78b746185c11282bdbe3fb7f8c5d4b
DISTNAME=	bbk
PKGNAME=	bbk_cli-1.0
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=dotse/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.bredbandskollen.se/en/bredbandskollen-cli/
COMMENT=	Bandwidth measurement tool for Nordic ISPs
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
MAKEFLAGS+=		CXX=${CXX}
BUILD_DIRS=		src/cli

LDFLAGS.SunOS+=		-lsocket

PKG_OPTIONS_VAR=	PKG_OPTIONS.bbk_cli
PKG_SUPPORTED_OPTIONS+=	tls
PKG_SUGGESTED_OPTIONS+=	tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtls)
.include "../../security/gnutls/buildlink3.mk"
PKGSRC_MAKE_ENV+=	GNUTLS=1
.endif

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cli/cli ${DESTDIR}${PREFIX}/bin/bbk_cli

.include "../../mk/bsd.pkg.mk"
