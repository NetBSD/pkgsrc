# $NetBSD: Makefile,v 1.53 2012/12/16 01:52:16 obache Exp $
#

DISTNAME=	feh-2.7
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://feh.finalrewind.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://feh.finalrewind.org/
COMMENT=	Advanced image viewer
LICENSE=	mit

#GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--program-transform-name=s,cam,feh_cam,

USE_TOOLS+=	bash:run perl:run gmake

REPLACE_BASH=		cam/gen-cam-menu
REPLACE_PERL=		scripts/*.pl cam/feh-cam

LDFLAGS.SunOS+=		-lnsl -lsocket

BUILDLINK_API_DEPENDS.giblib+=	giblib>=1.2.4

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/giblib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
