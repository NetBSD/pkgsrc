# $NetBSD: Makefile,v 1.4 2003/08/30 07:54:03 taca Exp $
# FreeBSD: ports/devel/ruby-strscan/Makefile,v 1.13 2001/01/27 09:41:20 knu Exp

DISTNAME=	strscan-0.6.7
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.loveruby.net/archive/strscan/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/strscan.html
COMMENT=	Fast string scanner class library for Ruby

DIST_SUBDIR=	ruby
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS_EN=	README.en doc.en/ChangeLog doc.en/umanual.html \
		doc.en/umanual.rd
DOCS_JA=	README.ja doc.ja/ChangeLog doc.ja/umanual.html \
		doc.ja/umanual.rd

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
