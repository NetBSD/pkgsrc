# $NetBSD: Makefile,v 1.21 2005/01/18 12:40:26 drochner Exp $
#

DISTNAME=	feh-1.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.linuxbrit.co.uk/feh/
COMMENT=	Advanced image viewer

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_X11=	YES

CONFIGURE_ARGS+=	--program-transform-name=s,cam,feh_cam,
REPLACE_PERL=		cam/cam

BUILDLINK_DEPENDS.giblib+=	giblib>=1.2.4
BUILDLINK_DEPENDS.jpeg+=	jpeg>=6bnb3 # includes jpegint.h

.include "../../devel/giblib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
