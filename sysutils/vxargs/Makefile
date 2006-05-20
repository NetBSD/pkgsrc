# $NetBSD: Makefile,v 1.1.1.1 2006/05/20 11:27:09 jmmv Exp $
#

DISTNAME=	vxargs-0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://dharma.cis.upenn.edu/planetlab/vxargs/
EXTRACT_SUFX=	.py

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://dharma.cis.upenn.edu/planetlab/vxargs/
COMMENT=	Runs parallel jobs with visualization and redirection

EXTRACT_CMD=	${CP} $${extract_file} ${WRKSRC}/vxargs.py
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

PYTHON_PATCH_SCRIPTS=	vxargs.py

.include "../../devel/py-curses/buildlink3.mk"
.include "../../lang/python/application.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vxargs.py ${PREFIX}/bin/vxargs

.include "../../mk/bsd.pkg.mk"
