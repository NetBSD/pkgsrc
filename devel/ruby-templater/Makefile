# $NetBSD: Makefile,v 1.3 2011/08/13 23:27:11 joerg Exp $

DISTNAME=	templater-1.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jnicklas/templater
COMMENT=	Tool copy files and render templates using ERB
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-highline>=1.4.0:../../devel/ruby-highline
DEPENDS+=	${RUBY_PKGPREFIX}-diff-lcs>=1.1.2:../../textproc/ruby-diff-lcs
DEPENDS+=	${RUBY_PKGPREFIX}-extlib>=0.9.5:../../devel/ruby-extlib

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
