# $NetBSD: Makefile,v 1.2 2014/05/17 16:10:47 wiz Exp $
#

DISTNAME=		labelnation-1.212
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		http://www.red-bean.com/labelnation/

MAINTAINER=		solevis@solevis.net
HOMEPAGE=		http://www.red-bean.com/labelnation/
COMMENT=		Command-line label, business card printing program
LICENSE=		gnu-gpl-v3

REPLACE_PYTHON= 	labelnation csv_to_ln

USE_LANGUAGES=		# none
NO_BUILD= 		yes

DOCDIR=                 share/doc/labelnation
EXAMPLESDIR=		share/examples/labelnation
INSTALLATION_DIRS=      bin ${DOCDIR} ${EXAMPLESDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/labelnation ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/csv_to_ln ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/*.* ${DESTDIR}${PREFIX}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
