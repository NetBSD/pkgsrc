# $NetBSD: Makefile,v 1.4 2020/08/06 16:31:21 adam Exp $

DISTNAME=	freexl-1.0.6
CATEGORIES=	textproc
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/freexl-sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gaia-gis.it/fossil/freexl/
COMMENT=	Library to extract valid data from an Excel spreadsheet
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	freexl.pc.in
TEST_TARGET=		check

LIBS.SunOS+=	-liconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
