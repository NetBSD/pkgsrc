# $NetBSD: Makefile,v 1.22.8.1 2015/02/20 20:07:12 tron Exp $

DISTNAME=	facter-2.4.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.puppetlabs.com/puppet/related-projects/facter/
COMMENT=	Cross-platform Ruby library for retrieving facts from OS
LICENSE=	gnu-gpl-v2

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
