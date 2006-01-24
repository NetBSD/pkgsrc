# $NetBSD: Makefile,v 1.18 2006/01/24 07:32:04 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	Python bindings and tools for Subversion

.include "../../devel/subversion/Makefile.common"

SHLIBTOOL_OVERRIDE=	libtool

CONFIGURE_ENV+=		PYTHON2=${PYTHONBIN:Q}

PY_PATCHPLIST=		YES
PYBINMODULE=		YES
PYTHON_PATCH_SCRIPTS=	tools/hook-scripts/mailer/mailer.py

BUILD_TARGET=		swig-py-lib swig-py
INSTALL_TARGET=		install-swig-py

MAKE_ENV+=		EXTRA_CPPFLAGS=${BUILDLINK_CPPFLAGS:Q}
MAKE_FLAGS+=		swig_pydir=${LOCALBASE}/${PYSITELIB}/libsvn \
			swig_pydir_extra=${LOCALBASE}/${PYSITELIB}/svn

TEST_TARGET=		all check check-swig-py

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

post-install:
	${INSTALL_DATA_DIR} ${SVNEXAMPLES}/python
	${INSTALL_DATA} ${WRKSRC}/tools/examples/*.py ${SVNEXAMPLES}/python
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/mailer.py \
		${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} \
		${WRKSRC}/tools/hook-scripts/mailer/mailer.conf.example \
		${SVNEXAMPLES}/hook-scripts

.include "../../devel/subversion/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
