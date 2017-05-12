# $NetBSD: Makefile,v 1.2 2017/05/12 11:28:51 jperkin Exp $

DISTNAME=	freexl-1.0.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	https://www.gaia-gis.it/fossil/freexl/
COMMENT=	Library to extract valid data from an Excel spreadsheet
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	freexl.pc.in

LIBS.SunOS+=	-liconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
