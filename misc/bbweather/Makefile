# $NetBSD: Makefile,v 1.9 2004/03/26 02:27:45 wiz Exp $
#

DISTNAME=	bbweather-0.6
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.netmeister.org/apps/bbweather/
COMMENT=	Show current weather conditions

DEPENDS+=	wget>=1.7:../../net/wget

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
REPLACE_PERL=		GrabWeather
USE_PERL5=		run

post-install:
	cd ${PREFIX}/man/man1 && ${GUNZIP_CMD} GrabWeather.1.gz
	cd ${PREFIX}/man/man1 && ${GUNZIP_CMD} bbweather.1.gz

.include "../../mk/bsd.pkg.mk"
