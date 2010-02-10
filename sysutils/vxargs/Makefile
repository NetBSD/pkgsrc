# $NetBSD: Makefile,v 1.4 2010/02/10 19:17:45 joerg Exp $
#

DISTNAME=	vxargs-0.3.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dharma.cis.upenn.edu/planetlab/vxargs/
EXTRACT_SUFX=	.py

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dharma.cis.upenn.edu/planetlab/vxargs/
COMMENT=	Runs parallel jobs with visualization and redirection

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_CMD=	${CP} $${extract_file} ${WRKSRC}/vxargs.py
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

PYTHON_PATCH_SCRIPTS=	vxargs.py

.include "../../devel/py-curses/buildlink3.mk"
.include "../../lang/python/application.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vxargs.py ${DESTDIR}${PREFIX}/bin/vxargs

.include "../../mk/bsd.pkg.mk"
