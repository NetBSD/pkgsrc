# $NetBSD: Makefile,v 1.96 2012/05/29 13:23:49 asau Exp $
#

DISTNAME=		mathomatic-15.8.5
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
INSTALL_ENV+=		prefix=$(PREFIX) mandir=$(DESTDIR)$(PREFIX)/$(PKGMANDIR)

CFLAGS.SunOS+=		-DSOLARIS

TEST_TARGET=		test

BUILDLINK_API_DEPENDS.readline+=	readline>=5.1pl1nb1
.include "../../devel/readline/buildlink3.mk"
#.include "../../devel/ncurses/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
