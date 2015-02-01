# $NetBSD: Makefile,v 1.12 2015/02/01 12:46:24 taca Exp $

DISTNAME=	rubyzip-1.1.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/aussiegeek/rubyzip
COMMENT=	Ruby module for reading and writing zip files
LICENSE=	ruby-license

RUBY_VERSION_SUPPORTED=	200 193 21

pre-configure:
	${CHMOD} -R -x ${WRKSRC}/Rakefile ${WRKSRC}/lib/zip/*.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
