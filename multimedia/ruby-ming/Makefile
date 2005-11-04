# $NetBSD: Makefile,v 1.1.1.1 2005/11/04 04:35:42 minskim Exp $

DISTNAME=	ming-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ming-${VER}
CATEGORIES=	multimedia
MASTER_SITES=	http://madscientist.jp/~ikegami/sources/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://madscientist.jp/~ikegami/ruby/ming/
COMMENT=	Ruby extension to drive the Ming SWF library

USE_RUBY_SETUP=	yes
VER=		0.1.6

EXAMPLES=		README action.rb button.rb drag.rb \
			gradient.rb gradientxform.rb keypress.rb \
			mousetrack.rb newbutton.rb shape.rb sparks.rb \
			sprite.rb
REPLACE_RUBY_DIRS=	${WRKSRC}/examples

post-install:
		${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/ming
.for f in ${EXAMPLES}
		${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/ming
.endfor

.include "../../multimedia/ming/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
