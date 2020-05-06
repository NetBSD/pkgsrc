# $NetBSD: Makefile,v 1.10 2020/05/06 14:56:16 taca Exp $

DISTNAME=	redmine-themes-1.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel meta-pkgs
MASTER_SITES=	# blank
DISTFILES=	# blank

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.redmine.org/
COMMENT=	Redmine themes meta package

DEPENDS+=	${RUBY_PKGPREFIX}-redmine-flatly-light-theme>=0.2.4:../../devel/ruby-redmine-flatly-light-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine-gitmike-theme>=1.2.0:../../devel/ruby-redmine-gitmike-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine-minimalflat-theme>=1.0.2:../../devel/ruby-redmine-minimalflat-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine-minimalflat2-theme>=1.7.0:../../devel/ruby-redmine-minimalflat2-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine-purplemine2-theme>=2.10.2:../../devel/ruby-redmine-purplemine2-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine-red-andy-theme>=1.00:../../devel/ruby-redmine-red-andy-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine-yh-theme>=1.6:../../devel/ruby-redmine-yh-theme

META_PACKAGE=		yes

RUBY_VERSIONS_ACCEPTED=	25 26

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
