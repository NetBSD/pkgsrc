# $NetBSD: Makefile,v 1.18 2004/10/03 00:17:55 tv Exp $
#

DISTNAME=	mtr-0.54
PKGNAME=	${DISTNAME:S/-/-gtk-/}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes
USE_X11=	yes

INSTALLATION_DIRS=	man/man8 sbin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mtr-gtk
	${INSTALL} -c -s -m 4755 -o ${ROOT_USER} -g ${ROOT_GROUP} ${WRKSRC}/mtr ${PREFIX}/sbin/mtr-gtk
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${PREFIX}/man/man8/mtr-gtk.8
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/mtr-gtk

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
