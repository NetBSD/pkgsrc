# $NetBSD: Makefile,v 1.1.1.1 2006/08/24 17:39:13 wiz Exp $
#

DISTNAME=		amaroc-0.3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amaroc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/amaroc/
COMMENT=		Command line interface to amarok

DEPENDS+=		${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/amaroc.py ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/amaroc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/amaroc

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
