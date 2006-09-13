# $NetBSD: Makefile,v 1.3 2006/09/13 13:13:02 obache Exp $

DISTNAME=	ming-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ming-${VER}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://rubyforge.org/frs/download.php/1765/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://mingruby.rubyforge.org/
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
