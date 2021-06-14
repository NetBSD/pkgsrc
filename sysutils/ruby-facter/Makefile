# $NetBSD: Makefile,v 1.43 2021/06/14 15:34:32 taca Exp $

DISTNAME=	facter-4.2.1
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
