# $NetBSD: Makefile,v 1.7 2015/11/25 23:45:10 wiedi Exp $

DISTNAME=	znapzend-0.14.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=oetiker/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/oetiker/znapzend/
COMMENT=	ZFS send/receive backup system
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl gmake

TEST_TARGET=	test

DEPENDS+=	p5-Mojolicious>=5.08:../../www/p5-Mojolicious
DEPENDS+=	p5-Mojo-IOLoop-ForkCall>=0.12:../../devel/p5-Mojo-IOLoop-ForkCall

.include "../../mk/bsd.pkg.mk"
