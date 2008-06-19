# $NetBSD: Makefile,v 1.9 2008/06/19 14:52:45 taca Exp $

DISTNAME=	ming-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ming-${VER}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://rubyforge.org/frs/download.php/15678/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mingruby.rubyforge.org/
COMMENT=	Ruby extension to drive the Ming SWF library

USE_RUBY_SETUP=	yes
VER=		0.1.8

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

EXAMPLES=		README.examples action.rb drag.rb \
			gradient.rb gradientxform.rb hello.rb keypress.rb \
			mousetrack.rb movieclip.rb newbutton.rb shape.rb
REPLACE_RUBY_DIRS=	examples
INSTALLATION_DIRS=	${RUBY_EG}/ming

post-install:
.for f in ${EXAMPLES}
		${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DESTDIR}${PREFIX}/${RUBY_EG}/ming
.endfor

.include "../../multimedia/ming/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
