# $NetBSD: Makefile,v 1.7 2005/01/28 14:08:01 taca Exp $
# FreeBSD: ports/devel/ruby-strscan/Makefile,v 1.13 2001/01/27 09:41:20 knu Exp

DISTNAME=	strscan-0.6.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/strscan/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/strscan.html
COMMENT=	Fast string scanner class library for Ruby

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION=		${RUBY16_VERSION}
USE_RUBY_SETUP=		yes
RUBY_SETUP=		install.rb

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

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
