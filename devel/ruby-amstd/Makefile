# $NetBSD: Makefile,v 1.7 2004/11/27 15:59:31 taca Exp $
# FreeBSD: ports/devel/ruby-amstd/Makefile,v 1.8 2000/12/06 15:38:58 knu Exp

DISTNAME=	amstd-2.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
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
