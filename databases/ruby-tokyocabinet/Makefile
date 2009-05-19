# $NetBSD: Makefile,v 1.12 2009/05/19 08:59:07 wiz Exp $
#

DISTNAME=	tokyocabinet-ruby-1.23
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby-/-/}
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/rubydoc/
COMMENT=	Ruby binding of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_EXTCONF=	yes
RUBY_HAS_ARCHLIB=	yes
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

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.15
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
