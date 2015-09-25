# $NetBSD: Makefile,v 1.4 2015/09/25 08:52:59 taca Exp $
#

DISTNAME=	memoize-1.3.1
CATEGORIES=	devel
MASTER_SITES=	# http://rubyforge.org/frs/download.php/61790/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/djberg96/memoize
COMMENT=	Speeds up methods at the cost of memory (or disk space)
LICENSE=	artistic-2.0

USE_LANGUAGES=	# none
NO_BUILD=	yes
USE_RAKE=	yes

INSTALLATION_DIRS+=	${RUBY_VENDORLIB}

do-test:
	${RUN} cd ${WRKSRC}; \
	${SETENV} ${TEST_ENV} ${RAKE} test

do-install:
	${RUN} cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${RAKE} install

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
