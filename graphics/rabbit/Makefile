# $NetBSD: Makefile,v 1.41 2013/06/16 08:39:43 obache Exp $
#

DISTNAME=	rabbit-2.0.9
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rabbit-shocker.org/download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rabbit-shocker.org/
COMMENT=	RD-document-based presentation application
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=0.90.3:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-rsvg-[0-9]*:../../graphics/ruby-gnome2-rsvg
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-poppler-[0-9]*:../../print/ruby-gnome2-poppler
DEPENDS+=	${RUBY_PKGPREFIX}-hikidoc-[0-9]*:../../textproc/ruby-hikidoc
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.20:../../textproc/ruby-rdtool
DEPENDS+=	${RUBY_PKGPREFIX}-rttool-[0-9]*:../../textproc/ruby-rttool
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.0.0:../../textproc/ruby-coderay
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-[0-9]*:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-gettext-[0-9]*:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-[0-9]*:../../www/ruby-faraday

USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
