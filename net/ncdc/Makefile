# $NetBSD: Makefile,v 1.34 2024/05/16 06:15:22 wiz Exp $

DISTNAME=	ncdc-1.23
PKGREVISION=	7
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
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.32
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
