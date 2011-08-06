# $NetBSD: Makefile,v 1.32 2011/08/06 13:39:27 obache Exp $
#

DISTNAME=	rabbit-1.0.4
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rabbit-shockers.org/download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rabbit-shockers.org/
COMMENT=	RD-document-based presentation application
LICENSE=	gnu-gpl-v2 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=0.90.3:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-rsvg-[0-9]*:../../graphics/ruby-gnome2-rsvg
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-poppler-[0-9]*:../../print/ruby-gnome2-poppler
DEPENDS+=	${RUBY_PKGPREFIX}-hikidoc-[0-9]*:../../textproc/ruby-hikidoc
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-sinatra-[0-9]*:../../www/ruby-sinatra
DEPENDS+=	${RUBY_PKGPREFIX}-rack-[0-9]*:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-haml-[0-9]*:../../textproc/ruby-haml
DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.20:../../textproc/ruby-rdtool
DEPENDS+=	${RUBY_PKGPREFIX}-coderay-[0-9]*:../../textproc/ruby-coderay

USE_RUBY_SETUP=	yes

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
