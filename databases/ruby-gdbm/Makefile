# $NetBSD: Makefile,v 1.14.8.1 2006/12/09 10:17:46 salo Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-gdbm-${RUBY_VERSION_SUFFIX}
CATEGORIES=		databases ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		ruby-1.8.5-gdbm-${RUBY18_PATCH_DATE}.patch.bz2
PATCH_DIST_STRIP=	-p3

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby extension to GDBM library

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
WRKSRC=			${RUBY_WRKSRC}/ext/gdbm
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/gdbm

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
