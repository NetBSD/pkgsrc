# $NetBSD: Makefile,v 1.27 2018/12/09 18:52:29 adam Exp $
#

DISTNAME=	gama-1.21
PKGREVISION=	4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GNU:=gama/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gnu.org/s/gama/
COMMENT=	Geodetic network adjustment (surveying)
LICENSE=	gnu-gpl-v2 # or later

USE_LANGUAGES=	c c++11
# Not documented, but apparent.
USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

INFO_FILES=	yes

TEST_TARGET=	check

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
