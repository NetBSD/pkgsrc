# $NetBSD: Makefile,v 1.1 2016/09/30 16:49:07 agc Exp $

DISTNAME=	httpstat-1.2.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=reorx/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/reorx/httpstat
COMMENT=	Visualise curl(1) statistics
LICENSE=	mit

REPLACE_PYTHON=	httpstat.py
NO_BUILD=	yes

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/httpstat.py ${DESTDIR}${PREFIX}/bin/httpstat

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
