# $NetBSD: Makefile,v 1.7 2010/03/21 16:29:40 wiz Exp $

DISTNAME=	courier-analog-0.15
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.courier-mta.org/
COMMENT=	Courier log analyzer
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
