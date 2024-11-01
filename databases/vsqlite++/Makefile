# $NetBSD: Makefile,v 1.28 2024/11/01 00:51:13 wiz Exp $

DISTNAME=	vsqlite++-0.3.13
PKGREVISION=	22
CATEGORIES=	databases
MASTER_SITES=	http://evilissimo.fedorapeople.org/releases/vsqlite--/0.3.13/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vsqlite.virtuosic-bytes.com/
COMMENT=	C++ SQLite wrapper library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--as-needed
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
