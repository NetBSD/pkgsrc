# $NetBSD: Makefile,v 1.1.1.1 2004/11/27 14:27:50 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-dbm-${RUBY_VERSION}
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby extension to DBM library

USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
WRKSRC=			${RUBY_WRKSRC}/ext/dbm
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/dbm \
			${RUBY_DISTNAME}/sample/dbmtest.rb

BDB_ACCEPTED?=		db1

post-install:
	${INSTALL_DATA} ${RUBY_WRKSRC}/sample/dbmtest.rb ${RUBY_EXAMPLESDIR}

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
