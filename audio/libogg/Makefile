# $NetBSD: Makefile,v 1.28 2004/02/14 18:26:27 jmmv Exp $

DISTNAME=	libogg-1.1
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/1.0.1/unix/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

GCC_REQD+=		2.95.3

PLIST_SUBST+=		DISTNAME=${DISTNAME}

PKGCONFIG_OVERRIDE+=	ogg.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
