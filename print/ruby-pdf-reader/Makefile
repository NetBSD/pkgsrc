# $NetBSD: Makefile,v 1.3 2011/12/15 15:45:25 taca Exp $

DISTNAME=	pdf-reader-0.10.1
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/yob/pdf-reader
COMMENT=	Library for accessing the content of PDF files
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-Ascii85>=1.0.0<1.1:../../converters/ruby-Ascii85

CONFLICTS+=	ruby[1-9][0-9]-pdf-reader-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
