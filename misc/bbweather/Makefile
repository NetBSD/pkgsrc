# $NetBSD: Makefile,v 1.5 2002/09/24 10:25:16 jlam Exp $
#

DISTNAME=	bbweather-0.5
CATEGORIES=	misc
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://www.netmeister.org/apps/bbweather/
COMMENT=	show current weather conditions

DEPENDS+=	wget>=1.7:../../net/wget

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
REPLACE_PERL=		GrabWeather

post-install:
	cd ${PREFIX}/man/man1 && ${GUNZIP_CMD} GrabWeather.1.gz
	cd ${PREFIX}/man/man1 && ${GUNZIP_CMD} bbweather.1.gz

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
