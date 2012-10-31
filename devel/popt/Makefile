# $NetBSD: Makefile,v 1.45 2012/10/31 11:19:25 asau Exp $
#

DISTNAME=	popt-1.16
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://rpm5.org/files/popt/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Command line option parsing library
# mit license with advertising clause
LICENSE=	mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS=		ORBit<=0.5.3

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	popt.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
