# $NetBSD: Makefile,v 1.2 2003/12/04 17:12:40 recht Exp $

PKGNAME=	${PYPKGPREFIX}-subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	Python bindings and tools for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ENV+=		PYTHON2=${PYTHONBIN}

PY_PATCHPLIST=		YES
PYBINMODULE=		YES
PYTHON_PATCH_SCRIPTS=	tools/cvs2svn/cvs2svn.py \
			tools/hook-scripts/mailer/mailer.py

ALL_TARGET=		swig-py-lib swig-py
INSTALL_TARGET=		install-swig-py-lib install-swig-py

MAKE_ENV+=		EXTRA_CPPFLAGS=${BUILDLINK_CPPFLAGS}
MAKEFLAGS+=		swig_pydir=${LOCALBASE}/${PYSITELIB}/libsvn \
			swig_pydir_extra=${LOCALBASE}/${PYSITELIB}/svn

TEST_TARGET=		all check

post-install:
	${RM} ${LOCALBASE}/${PYSITELIB}/libsvn/*.a
	${RM} ${LOCALBASE}/${PYSITELIB}/libsvn/*.la
	${INSTALL_DATA_DIR} ${SVNEXAMPLES}/python
	${INSTALL_DATA} ${WRKSRC}/tools/examples/*.py ${SVNEXAMPLES}/python
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/mailer.py \
		${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} \
		${WRKSRC}/tools/hook-scripts/mailer/mailer.conf.example \
		${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/subversion/cvs2svn
	${INSTALL_DATA} ${WRKSRC}/tools/cvs2svn/README ${SVNDOC}/cvs2svn
	${INSTALL_SCRIPT} ${WRKSRC}/tools/cvs2svn/cvs2svn.py \
		${PREFIX}/bin/cvs2svn
	${INSTALL_SCRIPT_DIR} ${LOCALBASE}/${PYSITELIB}/rcsparse
	${INSTALL_SCRIPT} ${WRKSRC}/tools/cvs2svn/rcsparse/*.py \
		${LOCALBASE}/${PYSITELIB}/rcsparse

.include "../../devel/subversion/buildlink2.mk"
.include "../../devel/swig-build/buildlink2.mk"
.include "../../devel/swig-python/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
