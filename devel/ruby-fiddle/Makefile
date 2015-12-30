# $NetBSD: Makefile,v 1.12 2015/12/30 15:02:13 taca Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION_FULL}
RUBY_EXTNAME=		fiddle
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby fiddle library to wrap libffi

USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/fiddle \
			${RUBY_DISTNAME}/internal.h
WRKSRC=			${RUBY_WRKSRC}/ext/fiddle
MAKE_ENV+=		top_srcdir=../..

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
