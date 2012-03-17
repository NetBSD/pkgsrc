# $NetBSD: Makefile,v 1.1.1.1 2012/03/17 15:40:24 taca Exp $

DISTNAME=	uglifier-1.0.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/lautis/uglifier
COMMENT=	Ruby wrapper for UglifyJS JavaScript compressor
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-execjs>=0.3.0:../../lang/ruby-execjs
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0.2:../../textproc/ruby-multi_json

#CONFLICTS+=	ruby[1-9][0-9]-sass-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
