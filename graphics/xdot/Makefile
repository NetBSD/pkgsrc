# $NetBSD: Makefile,v 1.1 2013/01/05 22:12:33 wiz Exp $
#

DISTNAME=	xdot
PKGNAME=	xdot-20121124
CATEGORIES=	graphics
MASTER_SITES=	http://xdot.jrfonseca.googlecode.com/git/
EXTRACT_SUFX=	.py

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/jrfonseca/wiki/XDot
COMMENT=	Interactive viewer for graphs written in Graphviz's dot language
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
DIST_SUBDIR=	${PKGNAME_NOREV}
REPLACE_PYTHON=	xdot.py
INSTALLATION_DIRS=	bin

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xdot.py ${DESTDIR}${PREFIX}/bin/xdot

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
