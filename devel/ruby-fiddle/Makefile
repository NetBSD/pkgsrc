# $NetBSD: Makefile,v 1.24 2021/12/08 16:04:07 adam Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION}
PKGREVISION=		1
RUBY_EXTNAME=		fiddle
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby fiddle library to wrap libffi

USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/fiddle ${RUBY_DISTNAME}/include \
			${RUBY_DISTNAME}/internal.h 
WRKSRC=			${RUBY_WRKSRC}/ext/fiddle
MAKE_ENV+=		top_srcdir=../..

PLIST_VARS+=	fiddle

.include "../../lang/ruby/modules.mk"
.if ${RUBY_FIDDLE_VERSION} != "1.0.0"
PLIST.fiddle=	yes
.endif
.include "../../lang/ruby/Makefile.common"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
