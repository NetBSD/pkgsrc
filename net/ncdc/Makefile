# $NetBSD: Makefile,v 1.25 2022/04/18 19:11:52 adam Exp $

DISTNAME=	ncdc-1.22.1
PKGREVISION=	11
CATEGORIES=	net
MASTER_SITES=	https://dev.yorhel.nl/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.yorhel.nl/ncdc
COMMENT=	Modern and lightweight direct connect client (curses interface)
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
