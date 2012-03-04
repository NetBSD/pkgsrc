# $NetBSD: Makefile,v 1.1.1.1 2012/03/04 16:10:39 taca Exp $

DISTNAME=	execjs-1.3.0
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sstephenson/execjs
COMMENT=	Run JavaScript code from Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json/

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
