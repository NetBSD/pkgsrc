# $NetBSD: Makefile,v 1.16 2005/04/11 21:46:29 tv Exp $
#

DISTNAME=	graphopt-0.4.1
PKGREVISION=	3
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=graphopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://schmuhl.org/graphopt/
COMMENT=	Optimize graph layouts

USE_DIRS+=	xdg-1.1
USE_LANGUAGES=	c++
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/graphopt
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/graphopt

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
