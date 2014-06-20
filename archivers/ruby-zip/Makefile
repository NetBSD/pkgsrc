# $NetBSD: Makefile,v 1.11 2014/06/20 02:09:43 rodent Exp $

DISTNAME=	rubyzip-1.1.4
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
