# $NetBSD: Makefile,v 1.45 2007/10/17 20:46:22 wiz Exp $

DISTNAME=	dialog-1.1-20070930
PKGNAME=	${DISTNAME:C/-2/.2/}
CATEGORIES=	misc
MASTER_SITES=	ftp://invisible-island.net/dialog/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dickey.his.com/dialog/dialog.html
COMMENT=	Display dialog boxes from shell scripts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
MAKE_FILE=	makefile

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-P]-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
