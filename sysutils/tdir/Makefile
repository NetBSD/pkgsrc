# $NetBSD: Makefile,v 1.7 2003/09/23 13:23:25 wiz Exp $
#

DISTNAME=	tdir-1.58
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tdir/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Display directories with files ordered by ending "extension"

LICENSE=	tdir-license

PYTHON_PATCH_SCRIPTS=	tdir

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tdir ${PREFIX}/bin/tdir
	${GUNZIP_CMD} ${WRKSRC}/tdir.1.gz
	${INSTALL_MAN} ${WRKSRC}/tdir.1 ${PREFIX}/man/man1/tdir.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tdir
	${INSTALL_DATA} ${WRKSRC}/tdir-license.txt ${PREFIX}/share/doc/tdir/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
