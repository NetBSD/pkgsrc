# $NetBSD: Makefile,v 1.40 2009/04/20 11:23:57 wiz Exp $
#

DISTNAME=	popt-1.15
CATEGORIES=	devel
MASTER_SITES=	http://rpm5.org/files/popt/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Command line option parsing library

# mit license with advertising clause
#LICENSE=	mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		ORBit<=0.5.3

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
