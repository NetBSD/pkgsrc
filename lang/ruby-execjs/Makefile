# $NetBSD: Makefile,v 1.2 2012/04/29 14:04:50 taca Exp $

DISTNAME=	execjs-1.3.1
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sstephenson/execjs
COMMENT=	Run JavaScript code from Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=1.0<2:../../textproc/ruby-multi_json/

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
