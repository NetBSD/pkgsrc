# $NetBSD: Makefile,v 1.2 2000/05/27 14:52:07 agc Exp $
#

DISTNAME=	jmk-x11-fonts-3.0
PKGNAME=	jmk-fonts-3.0
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=X11/fonts/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.ntrnet.net/~jmknoble/fonts/

USE_IMAKE=	yes
MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' \
		< ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
