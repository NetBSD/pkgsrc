# $NetBSD: Makefile,v 1.3 1999/11/03 23:57:03 hubertf Exp $
#

.include "../lame/Makefile.common"

PKGNAME=	lame-gui-${VERS}

DEPENDS=	gtk+-1.2.*:../../x11/gtk

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hive.me.gu.edu.au/not_lame/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin/lame-gui

.include "../../mk/bsd.pkg.mk"
