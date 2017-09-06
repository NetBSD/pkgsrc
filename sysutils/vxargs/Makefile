# $NetBSD: Makefile,v 1.10 2017/09/06 10:40:33 wiz Exp $

DISTNAME=	vxargs-0.3.3
PKGREVISION=	3
CATEGORIES=	sysutils
#MASTER_SITES=	http://dharma.cis.upenn.edu/planetlab/vxargs/
EXTRACT_SUFX=	.py

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://dharma.cis.upenn.edu/planetlab/vxargs/
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
