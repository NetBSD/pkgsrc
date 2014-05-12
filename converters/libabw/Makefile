# $NetBSD: Makefile,v 1.3 2014/05/12 12:09:11 ryoon Exp $

DISTNAME=	libabw-0.0.2
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://dev-www.libreoffice.org/src/
COMMENT=	Library for AbiWord documents
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

.include "../../mk/bsd.prefs.mk"
# GCC 4.5 or later may be required, and gcc45 is not provided for OpenBSD
.if ${OPSYS} == "OpenBSD"
GCC_REQD+=	4.6
.endif

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:build pkg-config
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libabw.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
