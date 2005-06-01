# $NetBSD: Makefile,v 1.37 2005/06/01 18:02:48 jlam Exp $

DISTNAME=	libXft-2.1.6
PKGNAME=	Xft2-2.1.6
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake

PKGCONFIG_OVERRIDE=	xft.pc.in
MAKE_ENV+=		EGREP="${EGREP}"

BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8.2
BUILDLINK_DEPENDS.fontconfig+=	fontconfig>=2.2

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
