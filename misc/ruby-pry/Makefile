# $NetBSD: Makefile,v 1.1 2014/06/03 15:08:21 jperkin Exp $

DISTNAME=	pry-0.9.12.6
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pry/pry
COMMENT=	IRB alternative and runtime developer console
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-method_source>=0.8.2<1.0:../../misc/ruby-method_source
DEPENDS+=	${RUBY_PKGPREFIX}-slop>=3.5.0<4.0:../../misc/ruby-slop
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.1.0<2.0:../../textproc/ruby-coderay

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
