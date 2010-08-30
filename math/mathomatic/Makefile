# $NetBSD: Makefile,v 1.92 2010/08/30 02:48:40 asau Exp $
#

DISTNAME=		mathomatic-15.2.0
CATEGORIES=		math
MASTER_SITES=		http://mathomatic.org/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://www.mathomatic.org/
COMMENT=		Small portable symbolic math program
LICENSE=		gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
MAKE_FILE=		makefile
USE_TOOLS+=		gmake

CFLAGS.SunOS+=		-DSOLARIS

TEST_TARGET=		test

BUILDLINK_API_DEPENDS.readline+=	readline>=5.1pl1nb1
.include "../../devel/readline/buildlink3.mk"
#.include "../../devel/ncurses/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
