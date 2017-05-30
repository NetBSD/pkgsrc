# $NetBSD: Makefile,v 1.33 2017/05/30 15:46:21 taca Exp $
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
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/gdbm
WRKSRC=			${RUBY_WRKSRC}/ext/gdbm

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
