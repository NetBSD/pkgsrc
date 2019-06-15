# $NetBSD: Makefile,v 1.19 2019/06/15 03:05:44 taca Exp $

DISTNAME=	rubyzip-1.2.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/aussiegeek/rubyzip
COMMENT=	Ruby module for reading and writing zip files
LICENSE=	ruby-license

pre-configure:
	${CHMOD} -R -x ${WRKSRC}/Rakefile ${WRKSRC}/lib/zip/*.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
