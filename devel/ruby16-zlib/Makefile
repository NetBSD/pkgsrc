# $NetBSD: Makefile,v 1.3 2005/01/28 14:19:35 taca Exp $
# FreeBSD: ports/archivers/ruby-zlib/Makefile,v 1.7 2000/09/26 22:01:12 knu Exp

DISTNAME=	ruby-zlib-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-zlib-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.blue.sky.or.jp/atelier/
COMMENT=	Zlib library for Ruby 1.6.X

VERSION=		0.6.0
RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION=		${RUBY16_VERSION}
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=		site-install
DOCS=			ChangeLog doc/zlib.html doc/zlib.rd \
			doc/zlib.ja.html doc/zlib.rd.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/zlib
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/zlib
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
