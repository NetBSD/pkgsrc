# $NetBSD: Makefile,v 1.1.1.1 2005/04/06 14:54:02 minskim Exp $

DISTNAME=	RMagick-1.7.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/3788/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby ImageMagick extension

RUBY_HAS_ARCHLIB=	yes
GNU_CONFIGURE=		yes
USE_GHOSTSCRIPT=	build
USE_X11=		yes

CONFIGURE_ARGS+=	--with-doc-dir=${RUBY_DOCDIR}/RMagick
CONFIGURE_ARGS+=	--without-graphics-magick

post-install:
	cd ${WRKSRC}/examples && \
		${PAX} -rw -pp -pm . ${RUBY_EXAMPLESDIR}/RMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
