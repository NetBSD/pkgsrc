# $NetBSD: Makefile,v 1.1.1.1 2002/03/27 13:52:52 taca Exp $
# FreeBSD: ports/japanese/ruby-uconv/Makefile,v 1.8 2001/01/30 19:26:22 knu Exp

DISTNAME=	uconv-0.4.9
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	japanese converters
MASTER_SITES=	http://www.yoshidam.net/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.yoshidam.net/Ruby.html#uconv
COMMENT=	Unicode conversion library with Japanese codesets support

DIST_SUBDIR=	ruby
USE_RUBY=	yes
USE_RUBY_EXTCONF= yes

WRKSRC=		${WRKDIR}/uconv
INSTALL_TARGET=	site-install

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

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
