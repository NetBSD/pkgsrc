# $NetBSD: Makefile,v 1.4 2009/01/04 15:11:50 shattered Exp $
#

DISTNAME=		amaroc-0.3
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amaroc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/amaroc/
COMMENT=		Command line interface to Amarok

DEPENDS+=		${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin share/doc/amaroc
PYTHON_PATCH_SCRIPTS=	amaroc.py

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/amaroc.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/amaroc
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/amaroc

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
