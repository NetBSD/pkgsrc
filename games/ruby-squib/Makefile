# $NetBSD: Makefile,v 1.8 2017/08/14 20:44:08 wiz Exp $

DISTNAME=	squib-0.13.4
#MASTER_SITES=	${MASTER_SITE_GITHUB:=andymeneely/}
CATEGORIES=	games
#GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squib.rocks/
COMMENT=	Tool for prototyping card and board games
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3.4:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.7.0:../../textproc/ruby-nokogiri
#DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config-[0-9]*:../../devel/ruby-pkg-config
DEPENDS+=	${RUBY_PKGPREFIX}-cairo>=1.15.9:../../graphics/ruby-cairo
DEPENDS+=	${RUBY_PKGPREFIX}-progressbar>=1.8:../../misc/ruby-progressbar
DEPENDS+=	${RUBY_PKGPREFIX}-roo>=2.7.0:../../math/ruby-roo
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-pango>=3.1.1:../../devel/ruby-gnome2-pango
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-rsvg>=3.1.1:../../graphics/ruby-gnome2-rsvg
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=3.1.1:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gio>=3.1.1:../../devel/ruby-gnome2-gio

RUBY_VERSIONS_ACCEPTED=	22 23 24
RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+=	roo>=2.7.0
OVERRIDE_GEMSPEC+=	gio2>=3.1.1
OVERRIDE_GEMSPEC+=	pango>=3.1.1
OVERRIDE_GEMSPEC+=	rsvg2>=3.1.1
OVERRIDE_GEMSPEC+=	gobject-introspection>=3.1.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
