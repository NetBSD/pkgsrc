# $NetBSD: Makefile,v 1.2 2004/09/24 12:33:16 wiz Exp $
#

DISTNAME=	libogg-1.1.2
CATEGORIES=	multimedia devel
MASTER_SITES=	http://downloads.xiph.org/releases/ogg/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

GCC_REQD+=	2.95.3

PLIST_SUBST+=	DISTNAME=${DISTNAME}

PKGCONFIG_OVERRIDE+=	ogg.pc.in

TEST_TARGET=	check

.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
