# $NetBSD: Makefile,v 1.3 2000/08/18 22:46:44 hubertf Exp $

DISTNAME=	mxDateTime-1.3.0
PKGNAME=	py-mxDateTime-1.3.0
WRKSRC=         ${WRKDIR}/DateTime
CATEGORIES=	misc
MASTER_SITES=	http://starship.python.net/~lemburg/
EXTRACT_SUFX=   .zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://starship.python.net/~lemburg/mxDateTime.html

BUILD_DEPENDS=  unzip:../../archivers/unzip
DEPENDS+=	python-1.5.2:../../lang/python

EXTRACT_CMD=	unzip -Laqo ${DOWNLOADED_DISTFILE}

RESTRICTED=	No commercial distribution
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

do-configure:
	( cd ${WRKSRC}/mxDateTime ; \
	make -f Makefile.pre.in boot )

do-build:
	( cd ${WRKSRC}/mxDateTime; make  )
	( cd ${WRKSRC}; python ${PREFIX}/lib/python1.5/compileall.py . )
	( cd ${WRKSRC}; python -O ${PREFIX}/lib/python1.5/compileall.py . )

do-install:
	@${INSTALL_SCRIPT_DIR} ${PREFIX}/lib/python1.5/site-packages
	@${INSTALL_SCRIPT_DIR} ${PREFIX}/lib/python1.5/site-packages/DateTime
	@${INSTALL_DATA} ${WRKSRC}/*.py* \
		${PREFIX}/lib/python1.5/site-packages/DateTime
	@${INSTALL_SCRIPT_DIR} \
		${PREFIX}/lib/python1.5/site-packages/DateTime/mxDateTime
	@${INSTALL_DATA} ${WRKSRC}/mxDateTime/*.so \
		${WRKSRC}/mxDateTime/__init__.py* \
		 ${PREFIX}/lib/python1.5/site-packages/DateTime/mxDateTime
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/py-mxDateTime
	@${INSTALL_SCRIPT} ${WRKSRC}/Doc/*.html \
		${PREFIX}/share/doc/py-mxDateTime/

.include "../../mk/bsd.pkg.mk"
