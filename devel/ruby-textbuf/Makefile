# $NetBSD: Makefile,v 1.3 2003/07/17 21:33:49 grant Exp $
# FreeBSD: ports/devel/ruby-textbuf/Makefile,v 1.1 2001/01/19 06:16:46 knu Exp

DISTNAME=	textbuf-0.3.8
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.loveruby.net/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/textbuf.html
COMMENT=	Gapped text buffer extention for Ruby

RUBY_REQD=	1.6
DIST_SUBDIR=	ruby
USE_RUBY_SETUP=	yes

DOCS=		README.en README.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/textbuf
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/textbuf
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
