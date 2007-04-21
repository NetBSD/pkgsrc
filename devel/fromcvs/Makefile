# $NetBSD: Makefile,v 1.1.1.1 2007/04/21 10:38:06 wiz Exp $

DISTNAME=	fromcvs-0.0.0_20070314
PKGNAME=	${DISTNAME:S/_/./}
CATEGORIES=	devel scm
MASTER_SITES=	#
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/fromcvs/
COMMENT=	CVS repository conversion tool

DEPENDS+=	${RUBY_PKGPREFIX}-rbtree>=0.2.0:../../devel/ruby-rbtree
DEPENDS+=	${RUBY_PKGPREFIX}-rcsparse>=0.0.0.20070210:../../devel/ruby-rcsparse
DEPENDS+=	${RUBY_PKGPREFIX}-sqlite3>=1.2.1:../../databases/ruby-sqlite3

LICENSE=        corecode-license

WRKSRC=		${WRKDIR}/fromcvs-e8d986fb9ba7

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/togit
	${ECHO} "${RUBY} -I${PREFIX}/share/ruby-fromcvs ${PREFIX}/share/ruby-fromcvs/togit.rb \"$$""@\"" >> ${WRKSRC}/togit
	${ECHO} "#!/bin/sh" > ${WRKSRC}/tohg
	${ECHO} "${RUBY} -I${PREFIX}/share/ruby-fromcvs ${PREFIX}/share/ruby-fromcvs/tohg.rb \"$$""@\"" >> ${WRKSRC}/tohg

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ruby-fromcvs
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ruby-fromcvs
	${INSTALL_DATA_DIR} ${PREFIX}/share/ruby-fromcvs
	${INSTALL_DATA_DIR} ${PREFIX}/share/ruby-fromcvs/commitset
	${INSTALL_DATA} ${WRKSRC}/commitset/* \
		${PREFIX}/share/ruby-fromcvs/commitset
	${INSTALL_DATA} ${WRKSRC}/*.rb ${PREFIX}/share/ruby-fromcvs
	${INSTALL_DATA} ${WRKSRC}/*.py ${PREFIX}/share/ruby-fromcvs
	${INSTALL_SCRIPT} ${WRKSRC}/togit ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tohg ${PREFIX}/bin

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
