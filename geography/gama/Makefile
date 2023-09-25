# $NetBSD: Makefile,v 1.65 2023/09/25 00:12:05 gdt Exp $
#

DISTNAME=	gama-2.25.1
CATEGORIES=	geography
#MASTER_SITES=	${MASTER_SITE_GNU:=gama/}
# temporary pending resolution of upstream signing issues
MASTER_SITES=	https://www.netbsd.org/~gdt/gama/

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
