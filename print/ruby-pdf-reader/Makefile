# $NetBSD: Makefile,v 1.12 2014/04/17 20:26:07 joerg Exp $

DISTNAME=	pdf-reader-1.3.3
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

RUBY_VERSION_SUPPORTED= 200 193 21

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
