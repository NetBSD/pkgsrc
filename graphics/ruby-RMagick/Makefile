# $NetBSD: Makefile,v 1.48 2008/02/14 08:44:57 obache Exp $

DISTNAME=	RMagick-2.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/32266/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby binding to ImageMagick

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

CONFIGURE_ARGS+=	--doc-dir=${DESTDIR}${RUBY_DOCDIR}/RMagick
USE_TOOLS+=	gs

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/RMagick
	cd ${WRKSRC}/examples && \
		${PAX} -rw -pp -pm . ${DESTDIR}${RUBY_EXAMPLESDIR}/RMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
