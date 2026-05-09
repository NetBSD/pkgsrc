# $NetBSD: Makefile,v 1.4 2026/05/09 17:33:07 vins Exp $

DISTNAME=	nq-1.0
PKGREVISION=	1
CATEGORIES=	misc sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://git.vuxu.org/nq/about/
COMMENT=	Command line queueing utility
LICENSE=	public-domain

USE_TOOLS+=	perl:test

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && ${OPSYS_VERSION} >= 051100
CPPFLAGS+=	-DHAVE_DPRINTF
.endif

REPLACE_SH=	nqterm

TEST_TARGET=	check

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
