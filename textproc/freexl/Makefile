# $NetBSD: Makefile,v 1.6 2024/05/06 10:13:01 adam Exp $

DISTNAME=	freexl-2.0.0
CATEGORIES=	textproc
MASTER_SITES=	https://www.gaia-gis.it/gaia-sins/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gaia-gis.it/fossil/freexl/index
COMMENT=	Library to extract valid data from an Excel spreadsheet
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	freexl.pc.in
TEST_TARGET=		check

.include "../../archivers/minizip/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
