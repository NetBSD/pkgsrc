# $NetBSD: Makefile,v 1.1.1.1 2000/01/16 23:26:50 jwise Exp $
#

DISTNAME=	jmk-x11-fonts-3.0
PKGNAME=	jmk-fonts-3.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=X11/fonts/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.ntrnet.net/~jmknoble/fonts/

USE_IMAKE=	yes
MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		< ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
