# $NetBSD: Makefile,v 1.4 2003/05/02 11:55:44 wiz Exp $
#

DISTNAME=	graphopt-0.3
PKGREVISION=	1
CATEGORIES=	math graphics
MASTER_SITES=	http://switch.dl.sourceforge.net/sourceforge/graphopt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://schmuhl.org/graphopt/
COMMENT=	optimize graph layouts

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/graphopt
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/graphopt
	${INSTALL_DATA_DIR} ${PREFIX}/share/graphopt
	${INSTALL_DATA_DIR} ${PREFIX}/share/graphopt/pixmaps
.for xpm in new.xpm open.xpm save.xpm save_as.xpm export.xpm \
	import.xpm quit.xpm
	${INSTALL_DATA} ${WRKSRC}/pixmaps/${xpm} \
		${PREFIX}/share/graphopt/pixmaps
.endfor

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
