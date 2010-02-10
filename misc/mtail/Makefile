# $NetBSD: Makefile,v 1.13 2010/02/10 19:17:42 joerg Exp $
#

DISTNAME=	mtail-1.1.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://matt.immute.net/src/mtail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://matt.immute.net/src/mtail/
COMMENT=	Small tail workalike that performs output coloring

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	mtail
INSTALLATION_DIRS=	bin share/doc share/examples

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mtail ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/mtail.README
	${INSTALL_DATA} ${WRKSRC}/mtailrc.sample \
		${DESTDIR}${PREFIX}/share/examples

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
