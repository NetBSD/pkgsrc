# $NetBSD: Makefile,v 1.3 2003/03/24 14:56:00 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}gdbm-${RUBY_VERSION}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby extension to GDBM library

DEPENDS+=	gdbm>=1.8.3:../../databases/gdbm

DIST_SUBDIR=	ruby
DISTINFO_FILE=	${RUBY_DISTINFO}
WRKSRC=		${RUBY_WRKSRC}/ext/gdbm
EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/ext/gdbm
USE_RUBY_EXTCONF= yes

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
