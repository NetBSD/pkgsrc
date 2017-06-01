# $NetBSD: Makefile,v 1.34 2017/06/01 22:14:45 taca Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION}
RUBY_EXTNAME=		gdbm
CATEGORIES=		databases ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to GDBM library

USE_RUBY_EXTCONF=	yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/gdbm ${RUBY_DISTNAME}/include
WRKSRC=			${RUBY_WRKSRC}/ext/gdbm
MAKE_ENV+=		top_srcdir=../..

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
