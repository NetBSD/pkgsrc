# $NetBSD: Makefile,v 1.6 2004/11/27 15:37:20 taca Exp $
# FreeBSD: ports/japanese/ruby-uconv/Makefile,v 1.8 2001/01/30 19:26:22 knu Exp

DISTNAME=	uconv-0.4.9
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	converters japanese ruby
MASTER_SITES=	http://www.yoshidam.net/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.yoshidam.net/Ruby.html#uconv
COMMENT=	Unicode conversion library with Japanese codesets support

USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/uconv

INSTALL_TARGET=		site-install

REPLACE_RUBY=	samples/euc2unicode.rb samples/unicode2euc.rb \
		samples/xmlconv.rb
EXAMPLES=	euc2unicode.rb test_euc.txt test_euc.xml trilang.xml \
		unicode2euc.rb xmlconv.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/uconv
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${RUBY_EXAMPLESDIR}/uconv
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/uconv
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/uconv
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_DOCDIR}/uconv

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
