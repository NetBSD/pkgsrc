# $NetBSD: Makefile,v 1.1.1.1 2001/06/30 23:13:25 taca Exp $
# FreeBSD: ports/archivers/ruby-zlib/Makefile,v 1.7 2000/09/26 22:01:12 knu Exp

DISTNAME=	ruby-zlib-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}zlib-${VERSION}
CATEGORIES=	archivers
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.blue.sky.or.jp/atelier/ruby/
COMMENT=	Zlib library for Ruby

VERSION=	0.4.0
DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes

INSTALL_TARGET=	site-install
DOCS_EN=	ChangeLog zlib.en.html
DOCS_JA=	zlib.ja.html

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/zlib/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/zlib
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/zlib/ja
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
