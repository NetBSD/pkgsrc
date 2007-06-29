# $NetBSD: Makefile,v 1.32 2007/06/29 20:22:46 tnn Exp $
#

DISTNAME=	feh-1.3.4
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://linuxbrit.co.uk/downloads/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://linuxbrit.co.uk/feh/
COMMENT=	Advanced image viewer

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--program-transform-name=s,cam,feh_cam,
REPLACE_PERL=		cam/cam

LDFLAGS.SunOS+=		-lnsl -lsocket

BUILDLINK_API_DEPENDS.giblib+=	giblib>=1.2.4
BUILDLINK_API_DEPENDS.jpeg+=	jpeg>=6bnb3 # includes jpegint.h

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/giblib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
