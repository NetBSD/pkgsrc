# $NetBSD: Makefile,v 1.17 2006/02/05 23:10:02 joerg Exp $
#

DISTNAME=	graphopt-0.4.1
PKGREVISION=	4
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
