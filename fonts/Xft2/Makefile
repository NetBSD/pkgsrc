# $NetBSD: Makefile,v 1.32 2004/10/03 00:14:42 tv Exp $

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
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_GNU_TOOLS+=		awk

PKGCONFIG_OVERRIDE=	xft.pc.in
MAKE_ENV+=		EGREP="${EGREP}"

BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
