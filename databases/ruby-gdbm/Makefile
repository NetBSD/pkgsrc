# $NetBSD: Makefile,v 1.8 2004/03/12 05:02:55 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}gdbm-${RUBY_VERSION}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby extension to GDBM library

DEPENDS+=	gdbm>=1.8.3:../../databases/gdbm

WRKSRC=		${RUBY_WRKSRC}/ext/gdbm
DIST_SUBDIR=	ruby
DISTINFO_FILE=	${RUBY_DISTINFO}
EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/ext/gdbm
USE_RUBY_EXTCONF= yes

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
