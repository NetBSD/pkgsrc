# $NetBSD: Makefile,v 1.22 2012/09/07 19:16:39 adam Exp $

DISTNAME=	SimGear-2.0.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	11
CATEGORIES=	games devel
MASTER_SITES=	ftp://mirrors.ibiblio.org/pub/mirrors/simgear/ftp/Source/ \
		ftp://ftp.goflyflightgear.com/simgear/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://simgear.sourceforge.net/
COMMENT=	Simulator Construction Tools

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-jpeg-factory

BUILDLINK_API_DEPENDS.plib+= plib>=1.8.4

.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
