# $NetBSD: Makefile,v 1.28 2026/08/31 15:15:43 taca Exp $

DISTNAME=	rubyzip-3.5.0
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
