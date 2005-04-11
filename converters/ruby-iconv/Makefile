# $NetBSD: Makefile,v 1.15 2005/04/11 21:45:09 tv Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-iconv-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	converters ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Iconv wrapper class for Ruby

RUBY_VERSION_SUPPORTED=	18
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
WRKSRC=         	${RUBY_WRKSRC}/ext/iconv
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/iconv

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
