# $NetBSD: Makefile,v 1.2 2001/12/30 17:03:35 taca Exp $
# FreeBSD: ports/devel/ruby-strscan/Makefile,v 1.13 2001/01/27 09:41:20 knu Exp

DISTNAME=	strscan-0.6.5
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.loveruby.net/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.loveruby.net/en/strscan.html
COMMENT=	Fast string scanner class library for Ruby

DIST_SUBDIR=	ruby
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS_EN=	README.en doc.en/changes.html doc.en/index.html \
		doc.en/reference.html doc.en/usage.html
DOCS_JA=	README.ja doc.ja/changes.html doc.ja/index.html \
		doc.ja/reference.html doc.ja/usage.html

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/strscan/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/strscan
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/strscan/ja
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
