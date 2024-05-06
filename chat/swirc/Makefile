# $NetBSD: Makefile,v 1.26 2024/05/06 08:27:49 jperkin Exp $

DISTNAME=	swirc-3.4.6
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	https://www.nifty-networks.net/swirc/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nifty-networks.net/swirc/
COMMENT=	Console based ICB and IRC client
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

USE_CXX_FEATURES=	c++17

MAKE_FLAGS+=	Q= CC="${CC}" CXX="${CXX}" LDFLAGS="${LDFLAGS}"
MAKE_FLAGS+=	DEST_MANUAL=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	DEST_CONFMAN=${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../devel/libidn/buildlink3.mk"
# Relies on ncurses struct internals - cannot use NetBSD libcurses.
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
