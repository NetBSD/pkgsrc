# $NetBSD: Makefile,v 1.11 2004/03/08 19:40:40 jmmv Exp $
#

DISTNAME=	graphopt-0.4.1
PKGREVISION=	2
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=graphopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://schmuhl.org/graphopt/
COMMENT=	Optimize graph layouts

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

USE_BUILDLINK2=	YES
USE_GCC_SHLIB=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/graphopt
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/graphopt

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
