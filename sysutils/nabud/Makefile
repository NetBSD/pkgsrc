# $NetBSD: Makefile,v 1.12 2024/05/19 19:08:23 thorpej Exp $
#

NABUD_VERS=	1.3.3

GITHUB_PROJECT=	nabud
GITHUB_TAG=	v${NABUD_VERS}

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${NABUD_VERS}
#PKGREVISION=	1
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

#
# nabud uses CommonCrypto and SecureTransport on Darwin.  It relies
# on OpenSSL everywhere else.
#
.if ${OPSYS} != "Darwin"
.include "../../security/openssl/buildlink3.mk"
.endif

#
# nabuctl uses the BSD libedit, but can also use other libraries with a
# compatible readline() function.
#
.if ${OPSYS} != "NetBSD" && ${OPSYS} != "FreeBSD" && \
    ${OPSYS} != "OpenBSD" && ${OPSYS} != "Darwin"
.include "../../devel/readline/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
