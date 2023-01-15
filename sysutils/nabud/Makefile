# $NetBSD: Makefile,v 1.1 2023/01/15 21:41:34 thorpej Exp $
#

NABUD_VERS=	0.9

GITHUB_PROJECT=	nabud
GITHUB_TAG=	v${NABUD_VERS}

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${NABUD_VERS}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=thorpej/}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/thorpej/nabud
COMMENT=	Server for the NABU Personal Computer
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

NABUD_USER?=	nabu
NABUD_GROUP?=	nabu

PKG_USERS=		${NABUD_USER}:${NABUD_GROUP}
PKG_GROUPS=		${NABUD_GROUP}
PKG_GECOS.${NABUD_USER}=NABU user

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
# nabud uses CommonCrypto and SecureTransport on Darwin.  It relies
# on OpenSSL everywhere else.
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
