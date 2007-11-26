# $NetBSD: Makefile,v 1.41 2007/11/26 03:21:30 obache Exp $

DISTNAME=	RMagick-1.15.11
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/28410/ \
		http://raa.ruby-lang.org/cache/rmagick/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby GraphicsMagick or ImageMagick extension

.include "options.mk"

RUBY_HAS_ARCHLIB=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-doc-dir=${RUBY_DOCDIR}/RMagick
USE_TOOLS+=	gs

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/RMagick
	cd ${WRKSRC}/examples && \
		${PAX} -rw -pp -pm . ${RUBY_EXAMPLESDIR}/RMagick

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
