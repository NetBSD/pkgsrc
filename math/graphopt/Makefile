# $NetBSD: Makefile,v 1.23 2011/04/22 13:44:06 obache Exp $
#

DISTNAME=	graphopt-0.4.1
PKGREVISION=	5
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=graphopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/graphopt/
COMMENT=	Optimize graph layouts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/graphopt
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/graphopt

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
