# $NetBSD: Makefile,v 1.27 2023/08/02 19:21:55 nia Exp $
#

DISTNAME=	graphopt-0.4.1
PKGREVISION=	5
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=graphopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/graphopt/
COMMENT=	Optimize graph layouts

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/graphopt
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/graphopt

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
