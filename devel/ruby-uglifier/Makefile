# $NetBSD: Makefile,v 1.4 2012/12/17 12:31:14 taca Exp $

DISTNAME=	uglifier-1.3.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/lautis/uglifier
COMMENT=	Ruby wrapper for UglifyJS JavaScript compressor
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-execjs>=0.3.0:../../lang/ruby-execjs
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.3<2:../../textproc/ruby-multi_json

OVERRIDE_GEMSPEC=	multi_json~>1.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
