# $NetBSD: Makefile,v 1.8 2014/01/25 10:45:21 wiz Exp $

DISTNAME=	vxargs-0.3.3
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://dharma.cis.upenn.edu/planetlab/vxargs/
EXTRACT_SUFX=	.py

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dharma.cis.upenn.edu/planetlab/vxargs/
COMMENT=	Runs parallel jobs with visualization and redirection

DEPENDS+=	${PYPKGPREFIX}-curses>=0nb4:../../devel/py-curses

EXTRACT_CMD=	${CP} $${extract_file} ${WRKSRC}/vxargs.py
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

REPLACE_PYTHON=	vxargs.py

.include "../../lang/python/application.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vxargs.py ${DESTDIR}${PREFIX}/bin/vxargs

.include "../../mk/bsd.pkg.mk"
