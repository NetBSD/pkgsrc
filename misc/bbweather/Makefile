# $NetBSD: Makefile,v 1.3 2002/07/01 23:53:38 wiz Exp $
#

DISTNAME=	bbweather-0.4
CATEGORIES=	misc
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.netmeister.org/apps/bbweather/
COMMENT=	show current weather conditions

DEPENDS+=	wget>=1.7:../../net/wget

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_PERL5=		YES
REPLACE_PERL=		GrabWeather

post-install:
	cd ${PREFIX}/man/man1 && ${GUNZIP_CMD} GrabWeather.1.gz
	cd ${PREFIX}/man/man1 && ${GUNZIP_CMD} bbweather.1.gz

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
