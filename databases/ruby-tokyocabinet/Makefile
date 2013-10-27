# $NetBSD: Makefile,v 1.26 2013/10/27 12:49:13 obache Exp $
#

DISTNAME=	tokyocabinet-ruby-1.31
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby-/-/}
CATEGORIES=	databases ruby
MASTER_SITES=	${HOMEPAGE:S/rubydoc/rubypkg/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://fallabs.com/tokyocabinet/rubydoc/
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
	cd ${WRKSRC}/doc && pax -rwpe . ${DESTDIR}${PREFIX}/${DOCDIR}
	${RUBY_GENERATE_PLIST}

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.29
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
