# $NetBSD: Makefile,v 1.2 2001/12/30 16:49:40 taca Exp $
# FreeBSD: ports/archivers/ruby-zlib/Makefile,v 1.7 2000/09/26 22:01:12 knu Exp

DISTNAME=	ruby-zlib-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}zlib-${VERSION}
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.blue.sky.or.jp/atelier/ruby/
COMMENT=	Zlib library for Ruby

VERSION=	0.4.0
DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes

INSTALL_TARGET=	site-install
DOCS=		ChangeLog zlib.en.html zlib.ja.html

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/zlib
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/zlib
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
