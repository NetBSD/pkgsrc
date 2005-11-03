# $NetBSD: Makefile,v 1.12 2005/11/03 07:20:28 taca Exp $

DISTNAME=	RMagick-1.9.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/6499/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby ImageMagick extension

RUBY_HAS_ARCHLIB=	yes
GNU_CONFIGURE=		yes
USE_GHOSTSCRIPT=	build

CONFIGURE_ARGS+=	--with-doc-dir=${RUBY_DOCDIR}/RMagick
CONFIGURE_ARGS+=	--without-graphics-magick

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/RMagick
	cd ${WRKSRC}/examples && \
		${PAX} -rw -pp -pm . ${RUBY_EXAMPLESDIR}/RMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
