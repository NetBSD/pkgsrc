# $NetBSD: Makefile,v 1.1.1.1 2010/03/12 09:23:51 pettai Exp $

DISTNAME=	dnsruby-1.44
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net

MAINTAINER=	pettai@nordu.net
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
