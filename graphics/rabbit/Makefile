# $NetBSD: Makefile,v 1.30 2011/07/11 09:37:50 obache Exp $
#

DISTNAME=	rabbit-0.9.3
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rabbit-shockers.org/download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rabbit-shockers.org/
COMMENT=	RD-document-based presentation application
LICENSE=	gnu-gpl-v2 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.20:../../textproc/ruby-rdtool
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=0.90.3:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-rsvg-[0-9]*:../../graphics/ruby-gnome2-rsvg
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-poppler-[0-9]*:../../print/ruby-gnome2-poppler
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-stream-[0-9]*:../../net/ruby-twitter-stream
DEPENDS+=	${RUBY_PKGPREFIX}-twitter_oauth-[0-9]*:../../security/ruby-twitter_oauth
DEPENDS+=	${RUBY_PKGPREFIX}-hikidoc-[0-9]*:../../textproc/ruby-hikidoc

USE_RUBY_SETUP=	yes

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

# temporary packaging miss
USE_TOOLS+=	msgfmt
post-extract:
	${RUN}cd ${WRKSRC}; ${SETENV} ${BUILD_ENV} ${RUBY} update-mo.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
