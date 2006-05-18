# $NetBSD: Makefile,v 1.20 2006/05/18 20:29:59 wiz Exp $

DISTNAME=	RMagick-1.10.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/8854/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby ImageMagick extension

BROKEN_IN=	pkgsrc-2006Q1

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
