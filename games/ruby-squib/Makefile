# $NetBSD: Makefile,v 1.14 2018/09/23 15:22:57 taca Exp $

DISTNAME=	squib-0.14.2
#MASTER_SITES=	${MASTER_SITE_GITHUB:=andymeneely/}
CATEGORIES=	games
#GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squib.rocks/
COMMENT=	Tool for prototyping card and board games
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3.6:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8.4:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-classy_hash>=0.2.1<0.3:../../devel/ruby-classy_hash
#DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config-[0-9]*:../../devel/ruby-pkg-config
DEPENDS+=	${RUBY_PKGPREFIX}-cairo>=1.15.13:../../graphics/ruby-cairo
DEPENDS+=	${RUBY_PKGPREFIX}-progressbar>=1.9.0:../../misc/ruby-progressbar
DEPENDS+=	${RUBY_PKGPREFIX}-roo>=2.7.1:../../math/ruby-roo
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-pango>=3.2.7:../../devel/ruby-gnome2-pango
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-rsvg>=3.2.7:../../graphics/ruby-gnome2-rsvg
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=3.2.7:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gio>=3.2.7:../../devel/ruby-gnome2-gio
DEPENDS+=	${RUBY_PKGPREFIX}-highline17>=1.7.10<1.8:../../devel/ruby-highline17

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
