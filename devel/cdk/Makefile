# $NetBSD: Makefile,v 1.2 1999/01/21 20:43:24 frueauf Exp $
#

DISTNAME=	cdk4x9x6
PKGNAME=	cdk-4.9.6
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.datasoft.on.ca/~cdk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.datasoft.on.ca/~cdk

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

MAKE_ENV+=	WRKSRC=${WRKSRC}

.include "../../mk/bsd.pkg.mk"
