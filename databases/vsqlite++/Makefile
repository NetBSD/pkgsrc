# $NetBSD: Makefile,v 1.17 2020/06/02 08:22:34 adam Exp $

DISTNAME=	vsqlite++-0.3.13
PKGREVISION=	13
CATEGORIES=	databases
MASTER_SITES=	http://evilissimo.fedorapeople.org/releases/vsqlite--/0.3.13/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vsqlite.virtuosic-bytes.com/
COMMENT=	C++ SQLite wrapper library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
