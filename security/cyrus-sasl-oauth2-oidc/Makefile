# $NetBSD: Makefile,v 1.2 2026/09/02 19:04:14 wiz Exp $

DISTNAME=		cyrus-sasl-oauth2-oidc-1.0.2
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=stefb69/}
GITHUB_PROJECT=		cyrus-sasl-oauth2-oidc
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-user@NetBSD.org
HOMEPAGE=		https://github.com/stefb69/cyrus-sasl-oauth2-oidc/
COMMENT=		Cyrus SASL OAuth2/OIDC Plugin
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		automake pkg-config

pre-configure:
	set -e; cd ${WRKSRC}; \
	${SH} ./autogen.sh

.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/liboauth2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
