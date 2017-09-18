# $NetBSD: Makefile,v 1.9 2017/09/18 06:43:42 taca Exp $

DISTNAME=	squib-0.13.4
#MASTER_SITES=	${MASTER_SITE_GITHUB:=andymeneely/}
PKGREVISION=	1
CATEGORIES=	games
#GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squib.rocks/
COMMENT=	Tool for prototyping card and board games
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3.6:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8.0:../../textproc/ruby-nokogiri
#DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config-[0-9]*:../../devel/ruby-pkg-config
DEPENDS+=	${RUBY_PKGPREFIX}-cairo>=1.15.9:../../graphics/ruby-cairo
DEPENDS+=	${RUBY_PKGPREFIX}-progressbar>=1.8.1:../../misc/ruby-progressbar
DEPENDS+=	${RUBY_PKGPREFIX}-roo>=2.7.1:../../math/ruby-roo
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-pango>=3.1.8:../../devel/ruby-gnome2-pango
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-rsvg>=3.1.8:../../graphics/ruby-gnome2-rsvg
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=3.1.8:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gio>=3.1.8:../../devel/ruby-gnome2-gio

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
