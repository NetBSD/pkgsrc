# $NetBSD: Makefile,v 1.9 2005/03/24 21:12:53 wiz Exp $

DISTNAME=	amstd-2.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/amstd/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/amstd.html
COMMENT=	Collection of miscellaneous Ruby modules

USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		README.en README.ja manual.rd.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/amstd
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/amstd
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
