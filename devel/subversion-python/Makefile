# $NetBSD: Makefile,v 1.1.1.1 2003/05/25 09:09:40 epg Exp $

PKGNAME=	${PYPKGPREFIX}-subversion-${SVNVER}
COMMENT=	Python bindings and tools for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ENV+=		PYTHON2=${PYTHONBIN}

PY_PATCHPLIST=		YES
PYBINMODULE=		YES
PYTHON_PATCH_SCRIPTS=	tools/cvs2svn/cvs2svn.py tools/hook-scripts/mailer.py

ALL_TARGET=		swig-py-lib swig-py
INSTALL_TARGET=		install-swig-py-lib install-swig-py

MAKE_ENV+=		swig_pydir=${LOCALBASE}/${PYSITELIB}/svn

TEST_TARGET=		all check

post-install:
	${RM} ${LOCALBASE}/${PYSITELIB}/svn/*.a
	${RM} ${LOCALBASE}/${PYSITELIB}/svn/*.la
	${INSTALL_DATA_DIR} ${SVNEXAMPLES}/python
	${INSTALL_DATA} ${WRKSRC}/tools/examples/*.py ${SVNEXAMPLES}/python
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer.py \
		${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer.conf.example \
		${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/subversion/cvs2svn
	${INSTALL_DATA} ${WRKSRC}/tools/cvs2svn/README ${SVNDOC}/cvs2svn
	${INSTALL_PROGRAM} ${WRKSRC}/tools/cvs2svn/cvs2svn.py \
		${PREFIX}/bin/cvs2svn
	${INSTALL_PROGRAM_DIR} ${LOCALBASE}/${PYSITELIB}/rcsparse
	${INSTALL_PROGRAM} ${WRKSRC}/tools/cvs2svn/rcsparse/*.py \
		${LOCALBASE}/${PYSITELIB}/rcsparse

.include "../../devel/subversion/buildlink2.mk"
.include "../../devel/swig-build/buildlink2.mk"
.include "../../devel/swig-python/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
