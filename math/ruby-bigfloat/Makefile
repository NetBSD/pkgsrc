# $NetBSD: Makefile,v 1.12 2005/03/24 21:12:56 wiz Exp $

DISTNAME=	bigfloat-1.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math ruby
MASTER_SITES=	http://www.tinyforest.gr.jp/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.tinyforest.gr.jp/ruby/bigfloat_en.html
COMMENT=	Variable precision floating library for Ruby

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}
INSTALL_TARGET=		site-install
DOCS=			README

# This extention library was replaced by BigDecimal in Ruby 1.8 later.
RUBY_VERSION=		${RUBY16_VERSION}

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/bigfloat
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/bigfloat
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
