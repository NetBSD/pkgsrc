# $NetBSD: Makefile,v 1.17 2010/02/10 19:17:45 joerg Exp $
#

DISTNAME=	tdir-1.58
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tdir/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Display directories with files ordered by ending "extension"
LICENSE=	tdir-license

PKG_DESTDIR_SUPPORT=	user-destdir

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
