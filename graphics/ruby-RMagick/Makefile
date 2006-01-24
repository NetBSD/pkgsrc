# $NetBSD: Makefile,v 1.15 2006/01/24 07:32:17 wiz Exp $

DISTNAME=	RMagick-1.9.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/6499/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby ImageMagick extension

RUBY_HAS_ARCHLIB=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gs

CONFIGURE_ARGS+=	--with-doc-dir=${RUBY_DOCDIR}/RMagick
CONFIGURE_ARGS+=	--without-graphics-magick

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/RMagick
	cd ${WRKSRC}/examples && \
		${PAX} -rw -pp -pm . ${RUBY_EXAMPLESDIR}/RMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
