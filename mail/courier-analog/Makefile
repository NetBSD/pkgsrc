# $NetBSD: Makefile,v 1.5 2008/02/19 18:45:09 jlam Exp $

DISTNAME=	courier-analog-0.15
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

#LICENSE=	gnu-gpl-v3

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.courier-mta.org/
COMMENT=	Courier log analyzer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
