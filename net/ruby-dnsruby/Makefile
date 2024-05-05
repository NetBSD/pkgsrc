# $NetBSD: Makefile,v 1.31 2024/05/05 17:05:58 taca Exp $

DISTNAME=	dnsruby-1.72.1
CATEGORIES=	net

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/alexdalitz/dnsruby
COMMENT=	Ruby DNS client library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-simpleidn>=0.2.1<0.3:../../devel/ruby-simpleidn

USE_LANGUAGES=	# none

post-extract:
	${MKDIR} ${WRKSRC}/html/classes
	${MKDIR} ${WRKSRC}/html/files

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
