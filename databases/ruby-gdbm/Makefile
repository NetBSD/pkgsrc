# $NetBSD: Makefile,v 1.4 2003/03/29 12:40:27 jmmv Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}gdbm-${RUBY_VERSION}
WRKSRC=		${RUBY_WRKSRC}/ext/gdbm
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby extension to GDBM library

DEPENDS+=	gdbm>=1.8.3:../../databases/gdbm

DIST_SUBDIR=	ruby
DISTINFO_FILE=	${RUBY_DISTINFO}
EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/ext/gdbm
USE_RUBY_EXTCONF= yes

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
