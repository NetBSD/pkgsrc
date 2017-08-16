# $NetBSD: Makefile,v 1.5 2017/08/16 20:45:37 wiz Exp $
#

DISTNAME=	amaze
PKGNAME=	amaze-0pre0
PKGREVISION=	1
CATEGORIES=	games
#MASTER_SITES=	http://adaptive-enterprises.com/~d/software/amaze/
DIST_SUBDIR=    ${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://adaptive-enterprises.com/~d/software/amaze/
COMMENT=	Curses-based maze game
LICENSE=	public-domain

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat6 ${PKGMANDIR}/man6
USE_BSD_MAKEFILE=	yes
USE_TOOLS=		nroff

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
