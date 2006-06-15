# $NetBSD: Makefile,v 1.10 2006/06/15 13:38:51 wiz Exp $
#

DISTNAME=	libogg-1.1.3
CATEGORIES=	multimedia devel
MASTER_SITES=	http://downloads.xiph.org/releases/ogg/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

GCC_REQD+=	2.95.3

PLIST_SUBST+=	DISTNAME=${DISTNAME:Q}

PKGCONFIG_OVERRIDE+=	ogg.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
