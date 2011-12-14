# $NetBSD: Makefile,v 1.7 2011/12/14 17:01:13 taca Exp $

DISTNAME=	rubyzip-0.9.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyzip.sourceforge.net/
COMMENT=	Ruby module for reading and writing zip files
LICENSE=	ruby-license

pre-configure:
	rm -f ${WRKSRC}/lib/download_quizzes.rb
	rm -fr ${WRKSRC}/lib/quiz1
	${CHMOD} -R g-w ${WRKSRC}
	${CHMOD} -R -x ${WRKSRC}/Rakefile ${WRKSRC}/lib/zip/*.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
