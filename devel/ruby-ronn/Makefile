# $NetBSD: Makefile,v 1.6 2022/12/29 16:23:51 taca Exp $

DISTNAME=		ronn-0.7.3
PKGREVISION=		4
CATEGORIES=		devel textproc

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://rtomayko.github.io/ronn/
COMMENT=		Manual authoring tool
LICENSE=		mit

DEPENDS+=		${RUBY_PKGPREFIX}-hpricot-[0-9]*:../../textproc/ruby-hpricot
DEPENDS+=		${RUBY_PKGPREFIX}-mustache-[0-9]*:../../devel/ruby-mustache
DEPENDS+=		${RUBY_PKGPREFIX}-rdiscount-[0-9]*:../../textproc/ruby-rdiscount

RUBYGEM_OPTIONS+=	--format-executable
RUBYGEM_MANPAGES=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
