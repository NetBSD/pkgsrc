# $NetBSD: Makefile,v 1.30 2022/01/06 13:53:40 taca Exp $
#

DISTNAME=	tokyocabinet-ruby-1.31
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby-/-/}
CATEGORIES=	databases ruby
MASTER_SITES=	${HOMEPAGE:S/rubydoc/rubypkg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dbmx.net/tokyocabinet/index.html
COMMENT=	Ruby binding of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

USE_RUBY_EXTCONF=	yes
REPLACE_RUBY_DIRS=	.
USE_TOOLS+=		pax

DOCDIR=			share/tokyocabinet/doc/ruby
RUBY_DYNAMIC_DIRS=	${DOCDIR}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${RUBY} test.rb

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/${DOCDIR}
	cd ${WRKSRC}/doc && pax -rwpp . ${DESTDIR}${PREFIX}/${DOCDIR}
	${RUBY_GENERATE_PLIST}

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.29
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
