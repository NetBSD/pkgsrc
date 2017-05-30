# $NetBSD: Makefile,v 1.18 2017/05/30 18:26:49 bsiegert Exp $

DISTNAME=	mosh-1.3.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://mosh.mit.edu/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://mosh.mit.edu/
COMMENT=	Remote terminal application which allows roaming
LICENSE=	gnu-gpl-v3

DEPENDS+=       p5-IO-tty>=1.08:../../devel/p5-IO-Tty

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

REPLACE_PERL+=	scripts/mosh.pl

.include "../../devel/protobuf/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=    zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
