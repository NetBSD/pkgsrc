# $NetBSD: Makefile,v 1.9 2004/10/03 00:13:33 tv Exp $

PKGNAME=	${PYPKGPREFIX}-subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	Python bindings and tools for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ENV+=		PYTHON2=${PYTHONBIN}

PY_PATCHPLIST=		YES
PYBINMODULE=		YES
PYTHON_PATCH_SCRIPTS=	tools/hook-scripts/mailer/mailer.py

ALL_TARGET=		swig-py-lib swig-py
INSTALL_TARGET=		install-swig-py

MAKE_ENV+=		EXTRA_CPPFLAGS="${BUILDLINK_CPPFLAGS}"
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

.include "../../devel/subversion/buildlink3.mk"
.include "../../devel/swig-build/buildlink3.mk"
.include "../../devel/swig-python/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
