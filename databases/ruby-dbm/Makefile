# $NetBSD: Makefile,v 1.7 2005/11/02 08:57:35 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-dbm-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby extension to DBM library

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION=		${RUBY16_VERSION}
USE_RUBY_EXTCONF=	yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
WRKSRC=			${RUBY_WRKSRC}/ext/dbm
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/dbm \
			${RUBY_DISTNAME}/sample/dbmtest.rb

post-install:
	${INSTALL_DATA} ${RUBY_WRKSRC}/sample/dbmtest.rb ${RUBY_EXAMPLESDIR}

.include "../../mk/bsd.prefs.mk"
#
# XXX:	Ruby extconf shuld select native ndbm(3) or Berkley DB's
#	ndbm(3) compatible support.
#
.if ${OPSYS} != "IRIX" && ${OPSYS} != "SunOS"
BDB_ACCEPTED?=		db1
.include "../../mk/bdb.buildlink3.mk"
.endif

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
