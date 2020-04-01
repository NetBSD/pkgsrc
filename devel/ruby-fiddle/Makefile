# $NetBSD: Makefile,v 1.20 2020/04/01 15:29:11 taca Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION}
RUBY_EXTNAME=		fiddle
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby fiddle library to wrap libffi

RUBY_VERSIONS_ACCEPTED=	24 25 26 27

USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/fiddle ${RUBY_DISTNAME}/include \
			${RUBY_DISTNAME}/internal.h 
WRKSRC=			${RUBY_WRKSRC}/ext/fiddle
MAKE_ENV+=		top_srcdir=../..

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
