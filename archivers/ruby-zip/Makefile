# $NetBSD: Makefile,v 1.8 2012/03/18 09:10:21 taca Exp $

DISTNAME=	rubyzip-0.9.6.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyzip.sourceforge.net/
COMMENT=	Ruby module for reading and writing zip files
LICENSE=	ruby-license

pre-configure:
	${CHMOD} -R -x ${WRKSRC}/Rakefile ${WRKSRC}/lib/zip/*.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
