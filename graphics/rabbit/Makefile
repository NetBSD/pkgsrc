# $NetBSD: Makefile,v 1.62 2020/03/20 00:57:59 joerg Exp $
#

DISTNAME=	rabbit-3.0.0
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rabbit-shocker.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rabbit-shocker.org/
COMMENT=	RD-document-based presentation application
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	${RUBY_PKGPREFIX}-gdk_pixbuf2>=3.0.9:../../graphics/ruby-gdk_pixbuf2
DEPENDS+=	${RUBY_PKGPREFIX}-gtk3>=3.3.8:../../x11/ruby-gtk3
DEPENDS+=	${RUBY_PKGPREFIX}-rsvg2>=3.3.8:../../graphics/ruby-rsvg2
DEPENDS+=	${RUBY_PKGPREFIX}-poppler>=3.3.8:../../print/ruby-poppler
DEPENDS+=	${RUBY_PKGPREFIX}-hikidoc-[0-9]*:../../textproc/ruby-hikidoc
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.20:../../textproc/ruby-rdtool
DEPENDS+=	${RUBY_PKGPREFIX}-rttool-[0-9]*:../../textproc/ruby-rttool
DEPENDS+=	${RUBY_PKGPREFIX}-coderay>=1.0.0:../../textproc/ruby-coderay
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-parser-gfm-[0-9]*:../../textproc/ruby-kramdown-parser-gfm
DEPENDS+=	${RUBY_PKGPREFIX}-gettext>=3.0.1:../../devel/ruby-gettext
DEPENDS+=	${RUBY_PKGPREFIX}-faraday-[0-9]*:../../www/ruby-faraday
DEPENDS+=	${RUBY_PKGPREFIX}-rouge-[0-9]*:../../www/ruby-rouge

RUBY_VERSIONS_INCOMPATIBLE=	24

USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		for f in *; do \
			${MV} $${f} $${f}${RUBY_SUFFIX}; \
		done

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
