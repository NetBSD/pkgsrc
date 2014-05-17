# $NetBSD: Makefile,v 1.18 2014/05/17 16:10:47 wiz Exp $
#

DISTNAME=	mtail-1.1.1
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://matt.immute.net/src/mtail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://matt.immute.net/src/mtail/
COMMENT=	Small tail workalike that performs output coloring

NO_BUILD=	yes

REPLACE_PYTHON=	mtail
INSTALLATION_DIRS=	bin share/doc share/examples

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mtail ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/mtail.README
	${INSTALL_DATA} ${WRKSRC}/mtailrc.sample \
		${DESTDIR}${PREFIX}/share/examples

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
