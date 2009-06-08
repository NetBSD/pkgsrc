# $NetBSD: Makefile,v 1.11 2009/06/08 01:08:40 obache Exp $
#

DISTNAME=	tokyotyrant-ruby-1.9
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby-/-/}
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/tyrantrubydoc/
COMMENT=	Pure Ruby Interface of Tokyo Tyrant
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# none
USE_TOOLS+=		pax
NO_BUILD=		yes
USE_RUBY_INSTALL=	yes

REPLACE_RUBY=		tcrtest.rb test.rb

DOCDIR=			share/tokytyrant/doc/ruby
RUBY_DYNAMIC_DIRS=	${DOCDIR}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${RUBY} test.rb

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/${DOCDIR}
	cd ${WRKSRC}/doc && pax -rwpe . ${DESTDIR}${PREFIX}/${DOCDIR}
	${RUBY_GENERATE_PLIST}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
