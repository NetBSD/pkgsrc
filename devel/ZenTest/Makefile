# $NetBSD: Makefile,v 1.4 2008/03/03 17:45:33 jlam Exp $

DISTNAME=	ZenTest-3.9.1
CATEGORIES=	devel ruby
#PKGREVISION=	1
MASTER_SITES=	http://rubyforge.org/frs/download.php/31587/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://zentest.rubyforge.org/
COMMENT=	Testing utilities for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
USE_LANGUAGES=	# none

REPLACE_RUBY=	bin/* lib/autotest/menu.rb

INSTALLATION_DIRS=	bin

.include "../../lang/ruby/modules.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB_DIR} ${DESTDIR}${RUBY_SITELIBDIR}
	cd ${WRKSRC}/lib && pax -rwppm . ${DESTDIR}${RUBY_SITELIBDIR}
	chmod ${SHAREMODE} ${DESTDIR}${RUBY_SITELIBDIR}/autotest.rb
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_DOCDIR}/${PKGBASE}
.for f in articles README.txt
	cd ${WRKSRC} && pax -rwppm ${f} ${DESTDIR}${RUBY_DOCDIR}/${PKGBASE}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/example* \
		${DESTDIR}${RUBY_EXAMPLESDIR}/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
