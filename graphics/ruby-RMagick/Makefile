# $NetBSD: Makefile,v 1.45 2008/01/31 06:18:24 obache Exp $

DISTNAME=	RMagick-2.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/31524/ \
		http://raa.ruby-lang.org/cache/rmagick/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby binding to ImageMagick

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

.include "../../mk/bsd.prefs.mk"

.if ${_USE_DESTDIR} != "no"
INSTALL_TARGET=		install --prefix=${DESTDIR}
.endif

CONFIGURE_ARGS+=	--doc-dir=${DESTDIR}${RUBY_DOCDIR}/RMagick
USE_TOOLS+=	gs

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/RMagick
	cd ${WRKSRC}/examples && \
		${PAX} -rw -pp -pm . ${DESTDIR}${RUBY_EXAMPLESDIR}/RMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
