# $NetBSD: Makefile,v 1.28 2023/04/30 15:19:00 taca Exp $

DISTNAME=	squib-0.19.0
#MASTER_SITES=	${MASTER_SITE_GITHUB:=andymeneely/}
CATEGORIES=	games
#GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://squib.rocks/
COMMENT=	Tool for prototyping card and board games
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.4.0<0.5:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.14.2<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-classy_hash>=1.0.0<1.1:../../devel/ruby-classy_hash
#DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config-[0-9]*:../../devel/ruby-pkg-config
#DEPENDS+=	${RUBY_PKGPREFIX}-cairo>=1.17.8<2:../../graphics/ruby-cairo
DEPENDS+=	${RUBY_PKGPREFIX}-progressbar>=1.11<2:../../misc/ruby-progressbar
DEPENDS+=	${RUBY_PKGPREFIX}-roo>=2.9<3:../../math/ruby-roo
DEPENDS+=	${RUBY_PKGPREFIX}-pango>=4.1.2<5:../../devel/ruby-pango
DEPENDS+=	${RUBY_PKGPREFIX}-rainbow>=3.1<4:../../misc/ruby-rainbow
DEPENDS+=	${RUBY_PKGPREFIX}-rsvg2>=4.1.2<5:../../graphics/ruby-rsvg2
#DEPENDS+=	${RUBY_PKGPREFIX}-gobject-introspection>=4.1.2<5:../../devel/ruby-gobject-introspection
#DEPENDS+=	${RUBY_PKGPREFIX}-gio2>=4.1.2<5:../../devel/ruby-gio2
DEPENDS+=	${RUBY_PKGPREFIX}-highline>=2.1.0:../../devel/ruby-highline

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	classy_hash>=0.2.1 gobject-introspection>=3.4
OVERRIDE_GEMSPEC+=	gio2>=3.4 highline>=2.0.0
OVERRIDE_GEMSPEC+=	mercenary>=0.4.0 pango>=3.4 rsvg2>=3.4

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
