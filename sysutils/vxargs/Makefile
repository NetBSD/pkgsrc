# $NetBSD: Makefile,v 1.15 2023/10/23 06:37:53 wiz Exp $

DISTNAME=	vxargs-0.3.3
PKGREVISION=	8
CATEGORIES=	sysutils
#MASTER_SITES=	http://dharma.cis.upenn.edu/planetlab/vxargs/
EXTRACT_SUFX=	.py

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://dharma.cis.upenn.edu/planetlab/vxargs/
COMMENT=	Runs parallel jobs with visualization and redirection

EXTRACT_CMD=	${CP} $${extract_file} ${WRKSRC}/vxargs.py
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

REPLACE_PYTHON=	vxargs.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vxargs.py ${DESTDIR}${PREFIX}/bin/vxargs

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
