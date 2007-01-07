# $NetBSD: Makefile,v 1.12 2007/01/07 09:14:13 rillig Exp $
#

DISTNAME=	tdir-1.58
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tdir/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Display directories with files ordered by ending "extension"

LICENSE=	tdir-license

USE_TOOLS+=		gunzip
PYTHON_PATCH_SCRIPTS=	tdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tdir ${PREFIX}/bin/tdir
	${GUNZIP_CMD} ${WRKSRC}/tdir.1.gz
	${INSTALL_MAN} ${WRKSRC}/tdir.1 ${PREFIX}/${PKGMANDIR}/man1/tdir.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tdir
	${INSTALL_DATA} ${WRKSRC}/tdir-license.txt ${PREFIX}/share/doc/tdir/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
