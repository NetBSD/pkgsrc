# $NetBSD: Makefile,v 1.13 2002/01/24 13:59:57 wiz Exp $
#

DISTNAME=	balsa-1.0.0
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/ \
		ftp://ftp.newton.cx/pub/balsa/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.balsa.net/
COMMENT=	GNOME EMail client

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--disable-more-warnings
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
USE_BUILDLINK_ONLY=	yes

USE_PTHREAD=	native pth

.include "../../devel/libtool/buildlink.mk"
.include "../../devel/libproplist/buildlink.mk"
.include "../../textproc/libpspell/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
