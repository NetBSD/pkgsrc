# $NetBSD: Makefile,v 1.3 2019/02/23 19:43:08 wiz Exp $

DISTNAME=	mblaze-0.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=chneukirchen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sunil@nimmagadda.net
HOMEPAGE=	https://github.com/chneukirchen/mblaze/
COMMENT=	Set of Maildir utilities
LICENSE=	public-domain

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:test
MAKE_FILE=	GNUmakefile
MAKE_FLAGS+=	PREFIX=${PREFIX:Q} BINDIR=${PREFIX:Q}/bin MANDIR=${PREFIX:Q}/${PKGMANDIR}

TEST_TARGET=	check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
