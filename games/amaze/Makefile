# $NetBSD: Makefile,v 1.4 2015/08/18 07:31:07 wiz Exp $
#

DISTNAME=	amaze
PKGNAME=	amaze-0pre0
PKGREVISION=	1
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
