# $NetBSD: Makefile,v 1.7 2019/11/03 19:35:55 rillig Exp $

DISTNAME=	redmine-themes-1.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel meta-pkgs
MASTER_SITES=	# blank
DISTFILES=	# blank

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.redmine.org/
COMMENT=	Redmine themes meta package

DEPENDS+=	${RUBY_PKGPREFIX}-redmine-flatly-light-theme-[0-9]*:../../devel/ruby-redmine-flatly-light-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine-gitmike-theme-[a-z0-9]*:../../devel/ruby-redmine-gitmike-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine-minimalflat-theme-[0-9]*:../../devel/ruby-redmine-minimalflat-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine-red-andy-theme-[0-9]*:../../devel/ruby-redmine-red-andy-theme

META_PACKAGE=		yes
RUBY_VERSIONS_ACCEPTED=	22

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
