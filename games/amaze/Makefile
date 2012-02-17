# $NetBSD: Makefile,v 1.1.1.1 2012/02/17 17:22:13 jakllsch Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat6 ${PKGMANDIR}/man6
USE_BSD_MAKEFILE=	yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
