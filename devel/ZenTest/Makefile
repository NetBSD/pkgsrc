# $NetBSD: Makefile,v 1.2 2007/08/08 16:13:46 joerg Exp $

DISTNAME=	ZenTest-3.6.0
CATEGORIES=	devel ruby
PKGREVISION=	1
MASTER_SITES=	http://rubyforge.org/frs/download.php/21081/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://zentest.rubyforge.org/
COMMENT=	Testing utilities for Ruby

NO_BUILD=	yes
USE_LANGUAGES=	# none

REPLACE_RUBY=	bin/* lib/autotest/menu.rb

INSTALLATION_DIRS=	bin

.include "../../lang/ruby/modules.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${PREFIX}/bin
	cd ${WRKSRC}/lib && pax -rwppm . ${RUBY_SITELIBDIR}
	chmod ${SHAREMODE} ${RUBY_SITELIBDIR}/autotest.rb
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/${PKGBASE}
.for f in LinuxJournalArticle.txt README.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PKGBASE}
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/example* ${RUBY_EXAMPLESDIR}/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
