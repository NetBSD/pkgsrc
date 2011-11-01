# $NetBSD: Makefile,v 1.51 2011/11/01 06:01:11 sbd Exp $

DISTNAME=	libXft-2.1.7
PKGNAME=	Xft2-2.1.7
PKGREVISION=	4
CATEGORIES=	fonts x11
MASTER_SITES=	http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

CONFLICTS+=	libXft-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE=	xft.pc.in
MAKE_ENV+=		EGREP=${EGREP:Q}

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.9.0nb2
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.2

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
