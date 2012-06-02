# $NetBSD: Makefile,v 1.3 2012/06/02 00:53:50 taca Exp $

DISTNAME=	execjs-1.4.0
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sstephenson/execjs
COMMENT=	Run JavaScript code from Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json/

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
