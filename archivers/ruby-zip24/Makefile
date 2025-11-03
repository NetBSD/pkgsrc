# $NetBSD: Makefile,v 1.1 2025/11/03 04:26:48 taca Exp $

DISTNAME=	rubyzip-2.4.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby//:S/zip/&24/}
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rubyzip/rubyzip
COMMENT=	Ruby module for reading and writing zip files
LICENSE=	ruby-license

USE_LANGUAGES=	# none

pre-configure:
	${CHMOD} -R -x ${WRKSRC}/Rakefile ${WRKSRC}/lib/zip/*.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
