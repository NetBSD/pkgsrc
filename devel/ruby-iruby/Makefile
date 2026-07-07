# $NetBSD: Makefile,v 1.20 2026/07/07 14:05:56 taca Exp $

DISTNAME=	iruby-0.8.3
CATEGORIES=	devel

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/SciRuby/iruby
COMMENT=	Ruby kernel for Jupyter/IPython frontends
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_uri>=0.1.0:../../www/ruby-data_uri
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-rzmq-[0-9]*:../../net/ruby-ffi-rzmq
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=3.3.1:../../mail/ruby-mime-types
DEPENDS+=	${PYPKGPREFIX}-ipython>=6.0.0:../../devel/py-ipython

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
