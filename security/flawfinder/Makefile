# $NetBSD: Makefile,v 1.20 2012/03/15 11:53:37 obache Exp $

DISTNAME=	flawfinder-1.27
PKGREVISION=	3
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dwheeler.com/flawfinder/
COMMENT=	Python program to find flaws in C/C++ programs

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	flawfinder
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flawfinder ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
