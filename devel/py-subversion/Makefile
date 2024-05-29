# $NetBSD: Makefile,v 1.105 2024/05/29 16:32:18 adam Exp $

PKGNAME=	${PYPKGPREFIX}-subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	Python bindings and tools for Subversion

.include "../../devel/subversion/Makefile.common"

SHLIBTOOL_OVERRIDE=	# empty
TOOLS_BROKEN+=		perl

CPPFLAGS+=		-P # for APR_INT64_T_FMT
CONFIGURE_ARGS+=	--with-py3c=${BUILDLINK_PREFIX.py-py3c}/${PYINC}/py3c
CONFIGURE_ARGS+=	--with-swig=${PREFIX}/bin/swig3.0
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

PY_PATCHPLIST=		YES
REPLACE_PYTHON=		tools/hook-scripts/mailer/mailer.py
PYTHON_SELF_CONFLICT=	YES

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_TARGET=		swig-py
INSTALL_TARGET=		install-swig-py

MAKE_ENV+=		EXTRA_CPPFLAGS=${BUILDLINK_CPPFLAGS:Q}
MAKE_FLAGS+=		swig_pydir=${LOCALBASE}/${PYSITELIB}/libsvn \
			swig_pydir_extra=${LOCALBASE}/${PYSITELIB}/svn

TEST_TARGET=		all check check-swig-py

INSTALLATION_DIRS=	${SVNEXAMPLES}/python ${SVNEXAMPLES}/hook-scripts

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

post-install:
	${INSTALL_DATA} ${WRKSRC}/tools/examples/*.py ${DESTDIR}${SVNEXAMPLES}/python
	${INSTALL_DATA} ${WRKSRC}/tools/hook-scripts/mailer/mailer.py \
		${DESTDIR}${SVNEXAMPLES}/hook-scripts
	${INSTALL_DATA} \
		${WRKSRC}/tools/hook-scripts/mailer/mailer.conf.example \
		${DESTDIR}${SVNEXAMPLES}/hook-scripts
	${PY_COMPILE_O_ALL} ${DESTDIR}${PREFIX}/${PYSITELIB}/libsvn
	${PY_COMPILE_O_ALL} ${DESTDIR}${PREFIX}/${PYSITELIB}/svn

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../devel/swig3/buildlink3.mk"
.include "../../lang/py-py3c/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
