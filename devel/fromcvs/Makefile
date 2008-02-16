# $NetBSD: Makefile,v 1.10 2008/02/16 13:23:09 wiz Exp $

DISTNAME=	d2883bf3ced6
# Last part of PKGNAME is changeset number
PKGNAME=	fromcvs-0.0.0.108
CATEGORIES=	devel scm
MASTER_SITES=	http://ww2.fs.ei.tum.de/~corecode/hg/fromcvs/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/fromcvs/
COMMENT=	CVS repository conversion tool

DEPENDS+=	${RUBY_PKGPREFIX}-rbtree>=0.2.0:../../devel/ruby-rbtree
DEPENDS+=	${RUBY_PKGPREFIX}-rcsparse>=0.0.0.37:../../devel/ruby-rcsparse
DEPENDS+=	${RUBY_PKGPREFIX}-sqlite3>=1.2.1:../../databases/ruby-sqlite3

LICENSE=        corecode-license

WRKSRC=		${WRKDIR}/fromcvs-${DISTNAME}
DIST_SUBDIR=	fromcvs

SUBST_CLASSES+=		python
SUBST_FILES.python+=	tohg.rb
SUBST_MESSAGE.python+=	Fixing path to Python interpreter.
SUBST_SED.python+=	-e "s!'python'!'${PYTHONBIN}'!"
SUBST_STAGE.python+=	pre-build

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/togit
	${ECHO} "${RUBY} -I${PREFIX}/share/fromcvs ${PREFIX}/share/fromcvs/togit.rb \"\$$@\"" >> ${WRKSRC}/togit
	${ECHO} "#!/bin/sh" > ${WRKSRC}/tohg
	${ECHO} "${RUBY} -I${PREFIX}/share/fromcvs ${PREFIX}/share/fromcvs/tohg.rb \"\$$@\"" >> ${WRKSRC}/tohg

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fromcvs
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fromcvs
	${INSTALL_DATA_DIR} ${PREFIX}/share/fromcvs
	${INSTALL_DATA_DIR} ${PREFIX}/share/fromcvs/commitset
	${INSTALL_DATA} ${WRKSRC}/commitset/* \
		${PREFIX}/share/fromcvs/commitset
	${INSTALL_DATA} ${WRKSRC}/*.rb ${PREFIX}/share/fromcvs
	${INSTALL_DATA} ${WRKSRC}/*.py ${PREFIX}/share/fromcvs
	${INSTALL_SCRIPT} ${WRKSRC}/togit ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tohg ${PREFIX}/bin

.include "../../lang/ruby/modules.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
