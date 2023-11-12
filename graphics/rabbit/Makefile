# $NetBSD: Makefile,v 1.68 2023/11/12 13:22:15 wiz Exp $
#

DISTNAME=	rabbit-3.0.3
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rabbit-shocker.org/
COMMENT=	RD-document-based presentation application
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	${RUBY_PKGPREFIX}-gdk_pixbuf2>=3.0.9:../../graphics/ruby-gdk_pixbuf2
#DEPENDS+=	${RUBY_PKGPREFIX}-gtk3>=3.3.8:../../x11/ruby-gtk3
DEPENDS+=	${RUBY_PKGPREFIX}-rsvg2>=3.3.8:../../graphics/ruby-rsvg2
DEPENDS+=	${RUBY_PKGPREFIX}-poppler>=3.3.8:../../print/ruby-poppler
DEPENDS+=	${RUBY_PKGPREFIX}-hikidoc-[0-9]*:../../textproc/ruby-hikidoc
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.20:../../textproc/ruby-rdtool
DEPENDS+=	${RUBY_PKGPREFIX}-rttool-[0-9]*:../../textproc/ruby-rttool
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.0.0:../../textproc/ruby-coderay
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-parser-gfm-[0-9]*:../../textproc/ruby-kramdown-parser-gfm
DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=3.0.1:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-rouge-[0-9]*:../../www/ruby-rouge

RUBYGEM_OPTIONS+=	--format-executable

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

.include "../../x11/ruby-gtk3/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
