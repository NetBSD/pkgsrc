# $NetBSD: Makefile,v 1.4 2010/06/06 20:31:30 pettai Exp $

DISTNAME=	dnsruby-1.47
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://dnsruby.rubyforge.org/
COMMENT=	Ruby DNS client library
LICENSE=	apache-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_BUILD=      gemspec

post-extract:
	${MKDIR} -p ${WRKSRC}/html/classes
	${MKDIR} -p ${WRKSRC}/html/files

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
