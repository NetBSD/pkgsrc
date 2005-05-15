# $NetBSD: Makefile,v 1.13 2005/05/15 22:02:27 jlam Exp $
#

DISTNAME=	bbweather-0.6.2
CATEGORIES=	misc
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.netmeister.org/apps/bbweather/
COMMENT=	Show current weather conditions

DEPENDS+=	wget>=1.7:../../net/wget

USE_X11=		YES
GNU_CONFIGURE=		YES
REPLACE_PERL=		GrabWeather
USE_PERL5=		run
PKGSRC_USE_TOOLS+=	gunzip

post-install:
	cd ${PREFIX}/man/man1 && ${GUNZIP_CMD} GrabWeather.1.gz
	cd ${PREFIX}/man/man1 && ${GUNZIP_CMD} bbweather.1.gz

.include "../../mk/bsd.pkg.mk"
