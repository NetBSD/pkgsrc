# $NetBSD: Makefile,v 1.1 2015/07/06 04:15:33 rodent Exp $

DISTNAME=	redmine-themes-1.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel meta-pkgs
MASTER_SITES=	# blank
DISTFILES=	# blank

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.redmine.org/
COMMENT=	Redmine themes meta package

DEPENDS+=	${RUBY_PKGPREFIX}-redmine-gitmike-theme-[a-z0-9]*:../../devel/ruby-redmine-gitmike-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine-minimalflat-theme-[0-9]*:../../devel/ruby-redmine-minimalflat-theme

META_PACKAGE=	yes

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
