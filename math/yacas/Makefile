# $NetBSD: Makefile,v 1.4 2000/12/05 19:02:05 drochner Exp $
#

DISTNAME=	yacas-latest
PKGNAME=	yacas-1.0.43
CATEGORIES=	math
MASTER_SITES=	http://www.xs4all.nl/~apinkus/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~apinkus/yacas.html

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}/${PKGNAME}

GNU_CONFIGURE=	YES

post-patch:
	cd ${WRKSRC}; ${SED} 's|@prefix@|${PREFIX}|g' yacas.sh.in > \
	  yacas.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yacas.sh ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
