# $NetBSD: Makefile,v 1.3 2011/11/08 15:24:39 taca Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION_FULL}
RUBY_EXTNAME=		fiddle
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby fiddle library to wrap libffi

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_VERSION_SUPPORTED= 19 193
USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/fiddle
WRKSRC=			${RUBY_WRKSRC}/ext/fiddle

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
