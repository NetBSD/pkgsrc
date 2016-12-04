# $NetBSD: Makefile,v 1.18 2016/12/04 05:17:28 ryoon Exp $
#

DISTNAME=	gama-1.18
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GNU:=gama/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gnu.org/s/gama/
COMMENT=	Geodetic network adjustment (surveying)
LICENSE=	gnu-gpl-v2 # or later

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

INFO_FILES=	yes

TEST_TARGET=	check

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
