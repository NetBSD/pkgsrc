# $NetBSD: Makefile,v 1.8 2008/04/04 15:31:39 jlam Exp $

DISTNAME=	ming-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ming-${VER}
CATEGORIES=	multimedia
MASTER_SITES=	http://rubyforge.org/frs/download.php/15678/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mingruby.rubyforge.org/
COMMENT=	Ruby extension to drive the Ming SWF library

USE_RUBY_SETUP=	yes
VER=		0.1.8

EXAMPLES=		README.examples action.rb drag.rb \
			gradient.rb gradientxform.rb hello.rb keypress.rb \
			mousetrack.rb movieclip.rb newbutton.rb shape.rb
REPLACE_RUBY_DIRS=	examples

post-install:
		${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/ming
.for f in ${EXAMPLES}
		${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/ming
.endfor

.include "../../multimedia/ming/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
