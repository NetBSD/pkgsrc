# $NetBSD: Makefile,v 1.61 2024/05/16 06:14:48 wiz Exp $

VERS=		1.9.20
DISTNAME=	pysvn-${VERS}
PKGNAME=	${PYPKGPREFIX}-pysvn-${VERS}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysvn/}

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		https://pysvn.sourceforge.io/
COMMENT=		Python interface to Subversion
LICENSE=		apache-1.1

USE_LANGUAGES=		c c++

WRKSRC=			${WRKDIR}/${DISTNAME}/Source

BUILDLINK_TRANSFORM.DragonFly+=	rm:-lresolv

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	setup_configure.py
SUBST_VARS.path+=	PREFIX

PYSETUPCONFIGARGS=	--verbose --pycxx-dir="../Import/pycxx-7.1.5"
PYLIBVER=		${PYVERSSUFFIX:S/./_/g}

PYTHON_VERSIONS_INCOMPATIBLE=	27 312

INSTALLATION_DIRS+=	${PYSITELIB}/pysvn

PRINT_PLIST_AWK+=	{ gsub(/${PYLIBVER}\.so/, "$${PYLIBVER}.so"); }

PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
PLIST_SUBST+=		PYLIBVER=${PYLIBVER:Q}

do-configure:
	${RUN} \
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} \
	${PYTHONBIN} setup.py configure ${PYSETUPCONFIGARGS}

do-install:
	${INSTALL_DATA} ${WRKSRC}/pysvn/__init__.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}/pysvn/__init__.py
	${INSTALL_LIB} ${WRKSRC}/pysvn/_pysvn_${PYLIBVER}.so \
		${DESTDIR}${PREFIX}/${PYSITELIB}/pysvn/_pysvn_${PYLIBVER}.so

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
