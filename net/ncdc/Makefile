# $NetBSD: Makefile,v 1.46 2026/09/02 19:04:01 wiz Exp $

DISTNAME=	ncdc-1.25
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://dev.yorhel.nl/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.yorhel.nl/ncdc
COMMENT=	Modern and lightweight direct connect client (curses interface)
LICENSE=	mit

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.32
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
