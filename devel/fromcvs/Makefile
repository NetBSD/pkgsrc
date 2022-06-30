# $NetBSD: Makefile,v 1.36 2022/06/30 11:18:13 nia Exp $

DISTNAME=	fromcvs-${VERS}
#PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel scm
MASTER_SITES=	-https://github.com/corecode/fromcvs/archive/${REVISION}.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/corecode/fromcvs/
COMMENT=	CVS repository conversion tool
LICENSE=	corecode-license

# This is our own version.
VERS=		0.0.0.134
REVISION=	568b30324bc2f6871cc6da5d0750b3cb2e612af3

DEPENDS+=	${RUBY_PKGPREFIX}-rbtree>=0.2.0:../../devel/ruby-rbtree
DEPENDS+=	${RUBY_PKGPREFIX}-rcsparse>=0.0.0.37:../../devel/ruby-rcsparse
DEPENDS+=	${RUBY_PKGPREFIX}-sqlite3>=1.2.1:../../databases/ruby-sqlite3

WRKSRC=		${WRKDIR}/fromcvs-${REVISION}

SUBST_CLASSES+=		python
SUBST_FILES.python+=	tohg.rb
SUBST_MESSAGE.python=	Fixing path to Python interpreter.
SUBST_SED.python+=	-e "s!'python'!'${PYTHONBIN}'!"
SUBST_STAGE.python=	pre-build

INSTALLATION_DIRS=	bin

post-extract:
	cd ${WRKSRC}; find . -type f -exec ${CHMOD} -x {} \;

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
