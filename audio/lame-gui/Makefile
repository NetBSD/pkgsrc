# $NetBSD: Makefile,v 1.4 1999/11/09 16:52:04 hubertf Exp $
#

.include "../lame/Makefile.common"

PKGNAME=	lame-gui-${VERS}

DEPENDS=	gtk+-1.2.*:../../x11/gtk

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hive.me.gu.edu.au/not_lame/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin/lame-gui
	${INSTALL_DATA} ${WRKSRC}/doc/man/lame.1 ${PREFIX}/man/man1/lame-gui.1

.include "../../mk/bsd.pkg.mk"
