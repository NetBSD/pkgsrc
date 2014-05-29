# $NetBSD: Makefile,v 1.2 2014/05/29 23:35:21 wiz Exp $

DISTNAME=	libfreehand-0.0.0
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://dev-www.libreoffice.org/src/
COMMENT=	Library for Adobe/Macromedia drawings
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:build pkg-config
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libfreehand.pc.in

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
