# $NetBSD: Makefile,v 1.20 2012/10/23 19:51:26 asau Exp $
#

DISTNAME=	tdir-1.58
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tdir/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display directories with files ordered by ending "extension"
LICENSE=	tdir-license

NOT_FOR_BULK_PLATFORM=	HPUX-*-*

USE_TOOLS+=		gunzip
PYTHON_PATCH_SCRIPTS=	tdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/tdir

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tdir ${DESTDIR}${PREFIX}/bin/tdir
	${GUNZIP_CMD} ${WRKSRC}/tdir.1.gz
	${INSTALL_MAN} ${WRKSRC}/tdir.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tdir.1
	${INSTALL_DATA} ${WRKSRC}/tdir-license.txt ${DESTDIR}${PREFIX}/share/doc/tdir/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
