# $NetBSD: Makefile,v 1.29 2022/06/30 11:18:52 nia Exp $
#

DISTNAME=	tdir-1.71
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tdir/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display directories with files ordered by ending "extension"
LICENSE=	tdir-license

USE_TOOLS+=		gunzip
REPLACE_PYTHON=		tdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/tdir

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tdir ${DESTDIR}${PREFIX}/bin/tdir
	${GUNZIP_CMD} ${WRKSRC}/tdir.1.gz
	${INSTALL_MAN} ${WRKSRC}/tdir.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tdir.1
	${INSTALL_DATA} ${WRKSRC}/tdir-license.txt ${DESTDIR}${PREFIX}/share/doc/tdir/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
