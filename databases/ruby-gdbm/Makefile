# $NetBSD: Makefile,v 1.16 2007/03/15 16:42:06 taca Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-gdbm-${RUBY_VERSION_SUFFIX}
CATEGORIES=		databases ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to GDBM library

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
WRKSRC=			${RUBY_WRKSRC}/ext/gdbm
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/gdbm

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
