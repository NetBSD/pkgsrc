# $NetBSD: Makefile,v 1.11 2023/08/01 23:20:41 wiz Exp $

DISTNAME=	iruby-0.7.4
CATEGORIES=	devel

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/SciRuby/iruby
COMMENT=	Ruby kernel for Jupyter/IPython frontends
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_uri>=0.1.0:../../www/ruby-data_uri
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-rzmq-[0-9]*:../../net/ruby-ffi-rzmq
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=3.3.1:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.11:../../textproc/ruby-multi_json
#DEPENDS+=	${RUBY_PKGPREFIX}-native-package-installer>=0:../../devel/ruby-native-package-installer

DEPENDS+=	${PYPKGPREFIX}-ipython>=6.0.0:../../devel/py-ipython

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

RUBYGEM_OPTIONS+=	--format-executable

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Versioned ipython command
SUBST_FILES.python=	lib/iruby/command.rb
SUBST_VARS.python=	PYVERSSUFFIX

.include "../../lang/ruby/gem.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
