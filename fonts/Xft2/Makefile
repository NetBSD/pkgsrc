# $NetBSD: Makefile,v 1.43 2006/01/24 07:32:07 wiz Exp $

DISTNAME=	libXft-2.1.7
PKGNAME=	Xft2-2.1.7
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE=	xft.pc.in
MAKE_ENV+=		EGREP=${EGREP:Q}

BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8.2
BUILDLINK_DEPENDS.fontconfig+=	fontconfig>=2.2

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
