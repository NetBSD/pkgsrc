# $NetBSD: Makefile,v 1.1.1.1 2001/06/30 23:31:20 taca Exp $
# FreeBSD: ports/devel/ruby-textbuf/Makefile,v 1.1 2001/01/19 06:16:46 knu Exp

DISTNAME=	textbuf-0.3.8
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www9.xdsl.ne.jp/~aamine/soft/ \
		http://www1.u-netsurf.ne.jp/~brew/mine/soft/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.xdsl.ne.jp/Cd/aamine/
COMMENT=	Gapped text buffer extention for Ruby

RUBY_REQD=	1.5
DIST_SUBDIR=	ruby
USE_RUBY_SETUP=	yes

DOCS_EN=	README.en
DOCS_JA=	README.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/textbuf/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/textbuf
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/textbuf/ja
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
