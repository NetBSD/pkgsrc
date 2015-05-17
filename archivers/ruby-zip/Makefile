# $NetBSD: Makefile,v 1.14 2015/05/17 13:02:56 sevan Exp $

DISTNAME=	rubyzip-1.1.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/aussiegeek/rubyzip
COMMENT=	Ruby module for reading and writing zip files
LICENSE=	ruby-license

RUBY_VERSION_SUPPORTED=	193 200 21 22

pre-configure:
	${CHMOD} -R -x ${WRKSRC}/Rakefile ${WRKSRC}/lib/zip/*.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
