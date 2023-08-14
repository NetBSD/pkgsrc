# $NetBSD: Makefile,v 1.16 2023/08/14 05:25:17 wiz Exp $
#

DISTNAME=		logfinder-0.1
PKGREVISION=		9
CATEGORIES=		sysutils
MASTER_SITES=		http://www.eff.org/osp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eff.org/osp/
COMMENT=		Eliminate Unwanted Logging of Personal Data

DEPENDS+=		lsof>=4.72:../../sysutils/lsof

NO_BUILD=		YES

REPLACE_PYTHON+=	${WRKSRC}/logfinder.py
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/logfinder.py ${DESTDIR}${PREFIX}/sbin/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
