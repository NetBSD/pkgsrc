# $NetBSD: Makefile,v 1.17 2019/08/11 13:23:21 wiz Exp $

DISTNAME=	znapzend-0.19.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=oetiker/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/oetiker/znapzend/
COMMENT=	ZFS send/receive backup system
LICENSE=	gnu-gpl-v3

GITHUB_TAG=	v${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl gmake

TEST_TARGET=	check

DEPENDS+=	p5-Mojolicious>=6.46:../../www/p5-Mojolicious
DEPENDS+=	p5-Mojo-IOLoop-ForkCall>=0.17:../../devel/p5-Mojo-IOLoop-ForkCall
DEPENDS+=	p5-Scalar-List-Utils>=1.45:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Test-Harness>=3.35:../../devel/p5-Test-Harness

.include "../../mk/bsd.pkg.mk"
