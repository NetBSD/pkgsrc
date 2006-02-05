# $NetBSD: Makefile,v 1.8 2006/02/05 23:10:12 joerg Exp $
#

DISTNAME=	mtail-1.0.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://matt.immute.net/src/mtail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://matt.immute.net/src/mtail/
COMMENT=	Small tail workalike that performs output coloring

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	mtail
INSTALLATION_DIRS=	bin share/examples

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mtail ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mtail.README
	${INSTALL_DATA} ${WRKSRC}/mtailrc.sample ${PREFIX}/share/examples

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
