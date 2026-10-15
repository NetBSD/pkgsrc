# $NetBSD: Makefile,v 1.14 2026/10/15 19:44:23 ktnb Exp $

DISTNAME=	mblaze-1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sunil@nimmagadda.net
HOMEPAGE=	https://github.com/leahneukirchen/mblaze/
COMMENT=	Set of Maildir utilities
LICENSE=	public-domain

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:test
MAKE_FILE=	GNUmakefile
MAKE_FLAGS+=	PREFIX=${PREFIX} BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/${PKGMANDIR}

TEST_TARGET=	check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
