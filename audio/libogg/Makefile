# $NetBSD: Makefile,v 1.25 2004/01/10 05:42:50 jlam Exp $

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
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCC_REQD=		2.95.3

PLIST_SUBST+=		DISTNAME=${DISTNAME}

PKGCONFIG_OVERRIDE+=	${WRKSRC}/ogg.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
