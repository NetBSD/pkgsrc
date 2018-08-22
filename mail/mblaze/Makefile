# $NetBSD: Makefile,v 1.2 2018/08/22 09:45:26 wiz Exp $

DISTNAME=	mblaze-0.4
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=chneukirchen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sunil@nimmagadda.net
HOMEPAGE=	https://github.com/chneukirchen/mblaze/
COMMENT=	Set of Maildir utilities
LICENSE=	public-domain

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
MAKE_FLAGS+=	PREFIX=${PREFIX:Q} BINDIR=${PREFIX:Q}/bin MANDIR=${PREFIX:Q}/${PKGMANDIR}

# Needs prove
TEST_DEPENDS+=	perl-[0-9]*:../../lang/perl5

TEST_TARGET=	check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
