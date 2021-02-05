# $NetBSD: Makefile,v 1.38 2021/02/05 15:54:35 taca Exp $

DISTNAME=	facter-4.0.50
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/puppetlabs/facter
COMMENT=	Cross-platform Ruby library for retrieving facts from OS
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-hocon>=1.3<2:../../devel/ruby-hocon
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=1.0.1:../../devel/ruby-thor

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
