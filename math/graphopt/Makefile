# $NetBSD: Makefile,v 1.5 2003/05/07 13:39:15 wiz Exp $
#

DISTNAME=	graphopt-0.4
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

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
