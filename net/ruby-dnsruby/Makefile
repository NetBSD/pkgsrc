# $NetBSD: Makefile,v 1.28 2023/04/29 13:54:20 taca Exp $

DISTNAME=	dnsruby-1.70.0
CATEGORIES=	net

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/alexdalitz/dnsruby
COMMENT=	Ruby DNS client library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-simpleidn>=0.1:../../devel/ruby-simpleidn

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC=	simpleidn>=0.1

post-extract:
	${MKDIR} ${WRKSRC}/html/classes
	${MKDIR} ${WRKSRC}/html/files

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
