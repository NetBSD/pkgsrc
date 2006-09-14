# $NetBSD: Makefile,v 1.5 2006/09/14 05:52:39 taca Exp $

DISTNAME=	ming-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ming-${VER}
CATEGORIES=	multimedia
MASTER_SITES=	http://rubyforge.org/frs/download.php/1841/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://mingruby.rubyforge.org/
COMMENT=	Ruby extension to drive the Ming SWF library

USE_RUBY_SETUP=	yes
VER=		0.1.7

EXAMPLES=		README.examples action.rb drag.rb \
			gradient.rb gradientxform.rb hello.rb keypress.rb \
			mousetrack.rb movieclip.rb newbutton.rb shape.rb
REPLACE_RUBY_DIRS=	${WRKSRC}/examples

post-install:
		${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/ming
.for f in ${EXAMPLES}
		${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/ming
.endfor

.include "../../multimedia/ming/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
