# $NetBSD: Makefile,v 1.35 2006/01/29 17:56:48 wiz Exp $

DISTNAME=	dialog-1.0-20060126
PKGNAME=	${DISTNAME:C/-2/.2/}
CATEGORIES=	misc
MASTER_SITES=	ftp://invisible-island.net/dialog/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dickey.his.com/dialog/dialog.html
COMMENT=	Display dialog boxes from shell scripts

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-P]-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
