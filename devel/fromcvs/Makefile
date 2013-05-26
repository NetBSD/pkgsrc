# $NetBSD: Makefile,v 1.31 2013/05/26 01:48:42 ryoon Exp $

DISTNAME=	fromcvs-fromcvs-184311d
# Bump simply to 0.0.0.133, I am not sure...
PKGNAME=	fromcvs-0.0.0.133
CATEGORIES=	devel scm
MASTER_SITES=	-http://gitorious.org/fromcvs/fromcvs/archive-tarball/184311d
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	
COMMENT=	CVS repository conversion tool
LICENSE=	corecode-license

DEPENDS+=	${RUBY_PKGPREFIX}-rbtree>=0.2.0:../../devel/ruby-rbtree
DEPENDS+=	${RUBY_PKGPREFIX}-rcsparse>=0.0.0.37:../../devel/ruby-rcsparse
DEPENDS+=	${RUBY_PKGPREFIX}-sqlite3>=1.2.1:../../databases/ruby-sqlite3

WRKSRC=		${WRKDIR}/fromcvs-fromcvs

RUBY_VERSION_SUPPORTED=	18

SUBST_CLASSES+=		python
SUBST_FILES.python+=	tohg.rb
SUBST_MESSAGE.python=	Fixing path to Python interpreter.
SUBST_SED.python+=	-e "s!'python'!'${PYTHONBIN}'!"
SUBST_STAGE.python=	pre-build

INSTALLATION_DIRS=	bin

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/togit
	${ECHO} "${RUBY} -rubygems -I${PREFIX}/share/fromcvs ${PREFIX}/share/fromcvs/togit.rb \"\$$@\"" >> ${WRKSRC}/togit
	${ECHO} "#!/bin/sh" > ${WRKSRC}/tohg
	${ECHO} "${RUBY} -rubygems -I${PREFIX}/share/fromcvs ${PREFIX}/share/fromcvs/tohg.rb \"\$$@\"" >> ${WRKSRC}/tohg

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/fromcvs
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/fromcvs
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/fromcvs
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/fromcvs/commitset
	${INSTALL_DATA} ${WRKSRC}/commitset/commitset \
		${DESTDIR}${PREFIX}/share/fromcvs/commitset
	${INSTALL_DATA} ${WRKSRC}/commitset/commitset.cgi \
		${DESTDIR}${PREFIX}/share/fromcvs/commitset
	${INSTALL_DATA} ${WRKSRC}/commitset/commitset.rb \
		${DESTDIR}${PREFIX}/share/fromcvs/commitset
	${INSTALL_DATA} ${WRKSRC}/*.rb ${DESTDIR}${PREFIX}/share/fromcvs
	${INSTALL_DATA} ${WRKSRC}/*.py ${DESTDIR}${PREFIX}/share/fromcvs
	${INSTALL_SCRIPT} ${WRKSRC}/togit ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tohg ${DESTDIR}${PREFIX}/bin

.include "../../lang/ruby/modules.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
