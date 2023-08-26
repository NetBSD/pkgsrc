# $NetBSD: Makefile,v 1.1 2023/08/26 10:54:11 vins Exp $

DISTNAME=	nq-0.5
CATEGORIES=	misc sysutils
MASTER_SITES=	https://git.vuxu.org/nq/snapshot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.vuxu.org/nq/about/
COMMENT=	Command line queueing utility
LICENSE=	public-domain

USE_TOOLS+=	perl:test

REPLACE_SH=	tq

TEST_TARGET=	check

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
