# $NetBSD: Makefile,v 1.35 2024/05/10 11:53:13 cheusov Exp $

DISTNAME=	mawk-1.3.4-20240123
PKGNAME=	${DISTNAME:S/-24/.24/}
CATEGORIES=	lang
MASTER_SITES=	https://invisible-island.net/archives/mawk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://www.invisible-island.net/mawk/
COMMENT=	AWK clone by Mike Brennan
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1

TEST_TARGET=		mawk_test fpe_test

.include "../../mk/bsd.pkg.mk"
