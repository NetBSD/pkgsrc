# $NetBSD: Makefile,v 1.2 2024/09/13 17:23:56 schmonz Exp $

DISTNAME=	nq-1.0
CATEGORIES=	misc sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.vuxu.org/nq/about/
COMMENT=	Command line queueing utility
LICENSE=	public-domain

USE_TOOLS+=	perl:test

REPLACE_SH=	nqterm

TEST_TARGET=	check

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
