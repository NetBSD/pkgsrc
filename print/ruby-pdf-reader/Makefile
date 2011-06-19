# $NetBSD: Makefile,v 1.1.1.1 2011/06/19 14:18:58 taca Exp $

DISTNAME=	pdf-reader-0.9.2
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/yob/pdf-reader
COMMENT=	Library for accessing the content of PDF files
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-Ascii85>=0.9:../../converters/ruby-Ascii85

CONFLICTS+=	ruby[1-9][0-9]-pdf-reader-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
