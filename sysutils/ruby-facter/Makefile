# $NetBSD: Makefile,v 1.32 2020/05/25 15:22:22 taca Exp $

DISTNAME=	facter-4.0.23
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/puppetlabs/facter-ng
COMMENT=	Cross-platform Ruby library for retrieving facts from OS
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-hocon>=1.3<2:../../devel/ruby-hocon
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=1.0.1:../../devel/ruby-thor

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
