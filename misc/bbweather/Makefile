# $NetBSD: Makefile,v 1.4 2002/07/06 22:47:25 jschauma Exp $
#

DISTNAME=	bbweather-0.5
CATEGORIES=	misc
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@netbsd.org
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
