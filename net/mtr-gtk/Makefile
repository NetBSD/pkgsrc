# $NetBSD: Makefile,v 1.3 2001/11/29 01:12:42 hubertf Exp $
#

DISTNAME=	mtr-0.42
PKGNAME=	mtr-gtk-0.42
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK_ONLY=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mtr-gtk
	${INSTALL} -c -s -m 4755 -o root -g wheel ${WRKSRC}/mtr ${PREFIX}/sbin/mtr-gtk
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${PREFIX}/man/man8/mtr-gtk.8
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${PREFIX}/share/doc/mtr-gtk

.include "../../devel/ncurses/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
