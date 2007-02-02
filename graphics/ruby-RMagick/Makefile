# $NetBSD: Makefile,v 1.29 2007/02/02 01:37:07 obache Exp $

DISTNAME=	RMagick-1.15.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/17048/ \
		http://raa.ruby-lang.org/cache/rmagick/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby GraphicsMagick or ImageMagick extension

.include "options.mk"

RUBY_HAS_ARCHLIB=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-doc-dir=${RUBY_DOCDIR}/RMagick

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/RMagick
	cd ${WRKSRC}/examples && \
		${PAX} -rw -pp -pm . ${RUBY_EXAMPLESDIR}/RMagick

.include "../../mk/x11.buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
