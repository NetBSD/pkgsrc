# $NetBSD: Makefile,v 1.3 2000/11/11 15:31:51 dmcmahill Exp $
#

DISTNAME=	yacas-latest
PKGNAME=	yacas-1.0.41
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
