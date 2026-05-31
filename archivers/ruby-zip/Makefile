# $NetBSD: Makefile,v 1.26 2026/05/31 14:43:35 taca Exp $

DISTNAME=	rubyzip-3.3.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rubyzip/rubyzip
COMMENT=	Ruby module for reading and writing zip files
LICENSE=	ruby-license

USE_LANGUAGES=	# none

pre-configure:
	${CHMOD} -R -x ${WRKSRC}/Rakefile ${WRKSRC}/lib/zip/*.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
