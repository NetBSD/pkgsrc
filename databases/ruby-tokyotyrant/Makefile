# $NetBSD: Makefile,v 1.20 2019/07/11 09:25:26 nia Exp $
#

DISTNAME=	tokyotyrant-ruby-1.13
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby-/-/}
CATEGORIES=	databases ruby
MASTER_SITES=	${HOMEPAGE:S/rubydoc/rubypkg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fallabs.com/tokyotyrant/rubydoc/
COMMENT=	Pure Ruby Interface of Tokyo Tyrant
LICENSE=	gnu-lgpl-v2.1

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
	cd ${WRKSRC}/doc && pax -rwpp . ${DESTDIR}${PREFIX}/${DOCDIR}
	${RUBY_GENERATE_PLIST}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
