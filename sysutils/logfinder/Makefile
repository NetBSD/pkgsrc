# $NetBSD: Makefile,v 1.9 2012/03/15 11:53:38 obache Exp $
#

DISTNAME=		logfinder-0.1
PKGREVISION=		4
CATEGORIES=		sysutils
MASTER_SITES=		http://www.eff.org/osp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eff.org/osp/
COMMENT=		Eliminate Unwanted Logging of Personal Data

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		lsof>=4.72:../../sysutils/lsof

NO_BUILD=		YES

PYTHON_PATCH_SCRIPTS+=	${WRKSRC}/logfinder.py
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/logfinder.py ${DESTDIR}${PREFIX}/sbin/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
