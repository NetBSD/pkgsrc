# $NetBSD: Makefile,v 1.10 2005/03/24 21:12:53 wiz Exp $

DISTNAME=	textbuf-0.3.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/textbuf.html
COMMENT=	Gapped text buffer extension for Ruby

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION=		${RUBY16_VERSION}
USE_RUBY_SETUP=		yes

DOCS=		README.en README.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/textbuf
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/textbuf
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
