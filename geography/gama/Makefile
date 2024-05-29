# $NetBSD: Makefile,v 1.70 2024/05/29 16:32:46 adam Exp $
#

DISTNAME=	gama-2.30
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GNU:=gama/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.gnu.org/s/gama/
COMMENT=	Geodetic network adjustment (surveying)
LICENSE=	gnu-gpl-v2 # or later

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	c++14

# Not documented, but apparent.
USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes

INFO_FILES=		yes

TEST_TARGET=		check

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
