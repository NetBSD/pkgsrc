# $NetBSD: Makefile,v 1.19 2020/03/24 00:34:50 taca Exp $

DISTNAME=	squib-0.15.3
#MASTER_SITES=	${MASTER_SITE_GITHUB:=andymeneely/}
CATEGORIES=	games
#GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://squib.rocks/
COMMENT=	Tool for prototyping card and board games
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3.6:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.10.4:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-classy_hash>=0.2.1<0.3:../../devel/ruby-classy_hash
#DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config-[0-9]*:../../devel/ruby-pkg-config
#DEPENDS+=	${RUBY_PKGPREFIX}-cairo>=1.16:../../graphics/ruby-cairo
DEPENDS+=	${RUBY_PKGPREFIX}-progressbar>=1.10<2:../../misc/ruby-progressbar
DEPENDS+=	${RUBY_PKGPREFIX}-roo>=2.8.2<2.9:../../math/ruby-roo
DEPENDS+=	${RUBY_PKGPREFIX}-pango>=3.4<4:../../devel/ruby-pango
DEPENDS+=	${RUBY_PKGPREFIX}-rsvg2>=3.4<4:../../graphics/ruby-rsvg2
#DEPENDS+=	${RUBY_PKGPREFIX}-gobject-introspection>=3.4<4:../../devel/ruby-gobject-introspection
#DEPENDS+=	${RUBY_PKGPREFIX}-gio2>=3.4<4:../../devel/ruby-gio2
DEPENDS+=	${RUBY_PKGPREFIX}-highline>=2.0.2<2.1:../../devel/ruby-highline

RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+=	mercenary>=0.3.6

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
