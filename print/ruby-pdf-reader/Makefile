# $NetBSD: Makefile,v 1.10 2013/03/12 13:42:09 taca Exp $

DISTNAME=	pdf-reader-1.3.2
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/yob/pdf-reader
COMMENT=	Library for accessing the content of PDF files
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-Ascii85>=1.0.0<1.1:../../converters/ruby-Ascii85
DEPENDS+=	${RUBY_PKGPREFIX}-rc4>=0:../../security/ruby-rc4
DEPENDS+=	${RUBY_PKGPREFIX}-hashery>=2.0<3:../../devel/ruby-hashery
DEPENDS+=	${RUBY_PKGPREFIX}-afm>=0.2.0<0.3:../../fonts/ruby-afm
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=0:../../fonts/ruby-ttfunk

CONFLICTS+=	ruby[1-9][0-9][0-9]-pdf-reader-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
