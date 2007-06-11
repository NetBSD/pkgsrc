# $NetBSD: Makefile,v 1.1.1.1 2007/06/11 03:05:44 minskim Exp $

DISTNAME=	rubyforge-0.4.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/20911/
EXTRACT_SUFX=	.gem

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/codeforpeople/
COMMENT=	Simplistic script automating RubyForge operations

NO_BUILD=	yes
USE_LANGUAGES=	# none
REPLACE_RUBY=	bin/rubyforge

INSTALLATION_DIRS=	bin

.include "../../lang/ruby/modules.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/rubyforge ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/http-access2
	${INSTALL_DATA} ${WRKSRC}/lib/http-access2/* \
		${RUBY_SITELIBDIR}/http-access2
	${INSTALL_DATA} ${WRKSRC}/lib/rubyforge.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/rubyforge
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_DOCDIR}/rubyforge

.include "../../mk/bsd.pkg.mk"
