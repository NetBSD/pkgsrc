# $NetBSD: Makefile,v 1.27 2013/11/16 07:08:14 shattered Exp $
#

DISTNAME=	bbweather-0.6.3
CATEGORIES=	misc
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netmeister.org/apps/bbweather/
COMMENT=	Show current weather conditions

DEPENDS+=	wget>=1.7:../../net/wget

GNU_CONFIGURE=		YES
REPLACE_PERL=		GrabWeather
USE_LANGUAGES=		c c++
USE_TOOLS+=		gunzip perl:run

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && ${GUNZIP_CMD} GrabWeather.1.gz
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && ${GUNZIP_CMD} bbweather.1.gz

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
