# $NetBSD: Makefile,v 1.26 2018/07/18 00:06:21 joerg Exp $
#

DISTNAME=	graphopt-0.4.1
PKGREVISION=	5
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=graphopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/graphopt/
COMMENT=	Optimize graph layouts

USE_LANGUAGES=	c c++03
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/graphopt
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/graphopt

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
