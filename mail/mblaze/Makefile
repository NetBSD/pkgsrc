# $NetBSD: Makefile,v 1.5 2019/08/11 13:21:29 wiz Exp $

DISTNAME=	mblaze-0.5.1
PKGREVISION=	1
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
