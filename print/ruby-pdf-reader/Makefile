# $NetBSD: Makefile,v 1.4 2012/03/20 13:08:33 taca Exp $

DISTNAME=	pdf-reader-1.0.0
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/yob/pdf-reader
COMMENT=	Library for accessing the content of PDF files
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-Ascii85>=1.0.0<1.1:../../converters/ruby-Ascii85
DEPENDS+=	${RUBY_PKGPREFIX}-rc4>=0:../../security/ruby-rc4

CONFLICTS+=	ruby[1-9][0-9]-pdf-reader-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
