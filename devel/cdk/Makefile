# $NetBSD: Makefile,v 1.1.1.1 1998/12/01 23:27:36 garbled Exp $

DISTNAME=		cdk4x9x6
PKGNAME=		cdk-4.9.6
CATEGORIES=		devel
MASTER_SITES=		http://www.datasoft.on.ca/~cdk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.datasoft.on.ca/~cdk

DEPENDS+=		ncurses-1.9.9g:../../devel/ncurses

WRKSRC=			${WRKDIR}/${PKGNAME}

MAKE_ENV+=		WRKSRC=${WRKSRC}

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=  yes
.endif

.include "../../mk/bsd.pkg.mk"
