# $NetBSD: Makefile,v 1.3 2002/01/05 05:32:15 taca Exp $
# FreeBSD: ports/math/ruby-bigfloat/Makefile,v 1.8 2000/10/02 14:57:26 knu Exp

DISTNAME=	bigfloat-1.1.8
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://www.tinyforest.gr.jp/ruby/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.tinyforest.gr.jp/ruby/bigfloat_en.html
COMMENT=	Variable precision floating library for Ruby

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes

WRKSRC=		${WRKDIR}
INSTALL_TARGET=	site-install

DOCS=		README

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/bigfloat
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/bigfloat
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
