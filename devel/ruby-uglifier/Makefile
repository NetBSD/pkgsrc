# $NetBSD: Makefile,v 1.5 2015/02/02 15:27:25 taca Exp $

DISTNAME=	uglifier-2.7.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/lautis/uglifier
COMMENT=	Ruby wrapper for UglifyJS JavaScript compressor
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-execjs>=0.3.0:../../lang/ruby-execjs
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.8.0:../../textproc/ruby-multi_json

RUBY_JSON_REQD=	1.8.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
