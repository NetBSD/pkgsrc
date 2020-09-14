# $NetBSD: Makefile,v 1.24 2020/09/14 13:29:27 taca Exp $

DISTNAME=	dnsruby-1.61.4
CATEGORIES=	net

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/alexdalitz/dnsruby
COMMENT=	Ruby DNS client library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.5<3:../../net/ruby-addressable

USE_LANGUAGES=	# none

post-extract:
	${MKDIR} ${WRKSRC}/html/classes
	${MKDIR} ${WRKSRC}/html/files

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
