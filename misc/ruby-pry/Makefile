# $NetBSD: Makefile,v 1.7 2016/11/19 14:38:03 taca Exp $

DISTNAME=	pry-0.10.4
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pry/pry
COMMENT=	IRB alternative and runtime developer console
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-method_source>=0.8.2<0.9:../../misc/ruby-method_source
DEPENDS+=	${RUBY_PKGPREFIX}-slop>=3.5.0<4.0:../../misc/ruby-slop
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.1.0<2.0:../../textproc/ruby-coderay

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
