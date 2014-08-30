# $NetBSD: Makefile,v 1.1 2014/08/30 11:03:11 wiedi Exp $

VERSION=	0.12.3
DISTNAME=	v${VERSION}
PKGNAME=	znapzend-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/oetiker/znapzend/archive/

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/oetiker/znapzend/
COMMENT=	ZFS send/receive backup system
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/znapzend-${VERSION}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl gmake

DEPENDS+=	p5-Mojolicious>=5.08:../../www/p5-Mojolicious
DEPENDS+=	p5-Mojo-IOLoop-ForkCall>=0.12:../../devel/p5-Mojo-IOLoop-ForkCall

.include "../../mk/bsd.pkg.mk"
