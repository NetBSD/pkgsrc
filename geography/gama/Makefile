# $NetBSD: Makefile,v 1.75 2024/12/19 14:18:03 gdt Exp $
#

DISTNAME=	gama-2.31
PKGREVISION=	4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GNU:=gama/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.gnu.org/s/gama/
COMMENT=	Geodetic network adjustment (surveying)
LICENSE=	gnu-gpl-v2 # or later

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	c++14

USE_TOOLS+=		gmake

# Upstream vendors an ancient copy of expat with many security issues.
# Remove it to ensure that it cannot be used.
post-extract:
	cd ${WRKSRC} && rm -rf lib/expat

GNU_CONFIGURE=		yes
# Remediate upstream default vendoring.
CONFIGURE_ARGS+=	--disable-expat_1_1

INFO_FILES=		yes

TEST_TARGET=		check
# \todo Some tests use xmllint.

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
