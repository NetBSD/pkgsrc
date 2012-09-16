# $NetBSD: Makefile,v 1.3 2012/09/16 14:22:01 taca Exp $

DISTNAME=	uglifier-1.2.7
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/lautis/uglifier
COMMENT=	Ruby wrapper for UglifyJS JavaScript compressor
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-execjs>=0.3.0:../../lang/ruby-execjs
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.3<2:../../textproc/ruby-multi_json

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
