# $NetBSD: Makefile,v 1.3 2008/03/03 17:45:37 jlam Exp $

DISTNAME=	rubyforge-0.4.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/20911/
EXTRACT_SUFX=	.gem

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/codeforpeople/
COMMENT=	Simplistic script automating RubyForge operations

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
USE_LANGUAGES=	# none
REPLACE_RUBY=	bin/rubyforge

INSTALLATION_DIRS=	bin

.include "../../lang/ruby/modules.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/rubyforge ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_SITELIBDIR}/http-access2
	${INSTALL_DATA} ${WRKSRC}/lib/http-access2/* \
		${DESTDIR}${RUBY_SITELIBDIR}/http-access2
	${INSTALL_DATA} ${WRKSRC}/lib/http-access2.rb \
		${DESTDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/rubyforge.rb \
		${DESTDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_DOCDIR}/rubyforge
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${RUBY_DOCDIR}/rubyforge

.include "../../mk/bsd.pkg.mk"
