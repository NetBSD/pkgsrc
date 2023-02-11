# $NetBSD: Makefile,v 1.51 2023/02/11 13:55:51 taca Exp $

DISTNAME=	facter-4.3.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/puppetlabs/facter
COMMENT=	Cross-platform Ruby library for retrieving facts from OS
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-hocon>=1.3<2:../../devel/ruby-hocon
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=1.0.1:../../devel/ruby-thor

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
