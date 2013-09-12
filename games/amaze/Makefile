# $NetBSD: Makefile,v 1.3 2013/09/12 11:15:12 jperkin Exp $
#

DISTNAME=	amaze
PKGNAME=	amaze-0pre0
CATEGORIES=	games
MASTER_SITES=	http://adaptive-enterprises.com/~d/software/amaze/
DIST_SUBDIR=    ${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://adaptive-enterprises.com/~d/software/amaze/
COMMENT=	Curses-based maze game
LICENSE=	public-domain

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat6 ${PKGMANDIR}/man6
USE_BSD_MAKEFILE=	yes
USE_TOOLS=		nroff

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
