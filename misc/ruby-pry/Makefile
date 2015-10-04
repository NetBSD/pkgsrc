# $NetBSD: Makefile,v 1.4 2015/10/04 13:02:20 taca Exp $

DISTNAME=	pry-0.10.2
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pry/pry
COMMENT=	IRB alternative and runtime developer console
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
DEPENDS+=	${RUBY_PKGPREFIX}-method_source>=0.8.2<0.9:../../misc/ruby-method_source
DEPENDS+=	${RUBY_PKGPREFIX}-slop>=3.5.0<4.0:../../misc/ruby-slop
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.1.0<2.0:../../textproc/ruby-coderay

RUBY_RDOC_REQD=	4.0.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
