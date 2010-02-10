# $NetBSD: Makefile,v 1.26 2010/02/10 19:17:35 joerg Exp $

DISTNAME=	c31a1dd9cbb2
# Last part of PKGNAME is changeset number
PKGNAME=	fromcvs-0.0.0.132
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://ww2.fs.ei.tum.de/~corecode/hg/fromcvs/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/fromcvs/
COMMENT=	CVS repository conversion tool
LICENSE=	corecode-license

DEPENDS+=	${RUBY_PKGPREFIX}-rbtree>=0.2.0:../../devel/ruby-rbtree
DEPENDS+=	${RUBY_PKGPREFIX}-rcsparse>=0.0.0.37:../../devel/ruby-rcsparse
DEPENDS+=	${RUBY_PKGPREFIX}-sqlite3>=1.2.1:../../databases/ruby-sqlite3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/fromcvs-${DISTNAME}
DIST_SUBDIR=	fromcvs

SUBST_CLASSES+=		python
SUBST_FILES.python+=	tohg.rb
SUBST_MESSAGE.python+=	Fixing path to Python interpreter.
SUBST_SED.python+=	-e "s!'python'!'${PYTHONBIN}'!"
SUBST_STAGE.python+=	pre-build

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
