# $NetBSD: Makefile,v 1.1.1.1 2005/02/12 00:32:58 jschauma Exp $
#

DISTNAME=		logfinder-0.1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.eff.org/osp/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.eff.org/osp/
COMMENT=		Eliminate Unwanted Logging of Personal Data

DEPENDS+=		lsof>=4.72:../../sysutils/lsof

USE_BUILDLINK3=		YES
NO_BUILD=		YES

PYTHON_PATCH_SCRIPTS+=	${WRKSRC}/logfinder.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/logfinder.py ${PREFIX}/sbin/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
