# $NetBSD: Makefile,v 1.1 1998/08/04 21:02:20 tron Exp $

DISTNAME=		battleball.20.src
PKGNAME=		battleball-2.0
CATEGORIES=		games x11
MASTER_SITES=		http://www.cs.utexas.edu/users/pahardin/

MAINTAINER=		root@garbled.net

WRKSRC=			${WRKDIR}/bb-2.0

NO_INSTALL_MANPAGES=	yes
USE_GMAKE=		yes
USE_IMAKE=		yes

post-patch:
	${TOUCH} ${WRKSRC}/battleball.man

.include "../../mk/bsd.pkg.mk"
