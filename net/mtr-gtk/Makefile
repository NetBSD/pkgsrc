# $NetBSD: Makefile,v 1.14 2003/09/27 17:07:37 grant Exp $
#

DISTNAME=	mtr-0.54
PKGNAME=	${DISTNAME:S/-/-gtk-/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BUILDLINK2=	yes
USE_X11=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mtr-gtk
	${INSTALL} -c -s -m 4755 -o ${ROOT_USER} -g ${ROOT_GROUP} ${WRKSRC}/mtr ${PREFIX}/sbin/mtr-gtk
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${PREFIX}/man/man8/mtr-gtk.8
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/mtr-gtk

.include "../../mk/curses.buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
