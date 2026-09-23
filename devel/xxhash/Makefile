# $NetBSD: Makefile,v 1.11 2026/09/23 12:38:18 adam Exp $

DISTNAME=	xxhash-0.8.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cyan4973/}
GITHUB_PROJECT=	xxHash
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cyan4973/xxHash
COMMENT=	Extremely fast non-cryptographic hash algorithm
LICENSE=	2-clause-bsd

USE_LIBTOOL=	yes
MAKE_ENV+=	MANDIR=${PKGMANDIR}
MAKE_ENV+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}

PKGCONFIG_OVERRIDE+=	libxxhash.pc.in

pre-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-test:
	cd ${WRKSRC} && ./xxhsum -b

.include "../../mk/bsd.pkg.mk"
