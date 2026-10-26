# $NetBSD: Makefile,v 1.21 2026/10/26 05:47:17 adam Exp $

DISTNAME=	iruby-0.8.3
CATEGORIES=	devel

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/SciRuby/iruby
COMMENT=	Ruby kernel for Jupyter/IPython frontends
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-data_uri>=0.1.0:../../www/ruby-data_uri
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-rzmq>=0:../../net/ruby-ffi-rzmq
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=3.3.1:../../mail/ruby-mime-types
DEPENDS+=	${PYPKGPREFIX}-ipython>=6.0.0:../../devel/py-ipython

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
