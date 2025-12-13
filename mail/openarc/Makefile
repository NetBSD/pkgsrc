# $NetBSD: Makefile,v 1.10 2025/12/13 12:41:53 wiz Exp $

DISTNAME=	openarc-20180921
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=trusteddomainproject/}
GITHUB_PROJECT=	OpenARC
GITHUB_TAG=	355ee2a1ca85acccce494478991983b54f794f4e

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trusteddomainproject/OpenARC
COMMENT=	Open source ARC library, MTA filter implementation and tools
LICENSE=	modified-bsd

CONFLICTS+=	flowerysong-openarc-[0-9]*

RCD_SCRIPTS=	openarc

USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-milter=${BUILDLINK_PREFIX.libmilter}

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	${EGDIR}

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

post-install:
	${INSTALL_DATA} ${WRKSRC}/openarc/openarc.conf.sample \
		${DESTDIR}${EGDIR}/

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
