# $NetBSD: Makefile,v 1.17 2014/06/07 12:11:23 wiz Exp $

DISTNAME=	libgexiv2_0.6.1
PKGNAME=	libgexiv2-0.6.1
PKGREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://yorba.org/download/gexiv2/0.6/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trac.yorba.org/wiki/gexiv2
COMMENT=	GObject-based wrapper around the Exiv2 library
LICENSE=	gnu-gpl-v2

# if needed to regenerate after patches
#BUILD_DEPENDS+=		vala-[0-9]*:../../lang/vala

WRKSRC=			${WRKDIR}/libgexiv2-0.6.1
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake m4 pkg-config bash
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

CONFIG_SHELL=		bash

PKGCONFIG_OVERRIDE=	gexiv2.m4

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
