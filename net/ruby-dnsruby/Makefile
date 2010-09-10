# $NetBSD: Makefile,v 1.6 2010/09/10 07:37:00 taca Exp $

DISTNAME=	dnsruby-1.49
CATEGORIES=	net

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://dnsruby.rubyforge.org/
COMMENT=	Ruby DNS client library
LICENSE=	apache-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

post-extract:
	${MKDIR} -p ${WRKSRC}/html/classes
	${MKDIR} -p ${WRKSRC}/html/files

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
