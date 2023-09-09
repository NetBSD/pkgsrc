# $NetBSD: Makefile,v 1.17 2023/09/09 13:52:56 taca Exp $

DISTNAME=	redmine-themes-1.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/redmine/redmine${RM_VER}/}
CATEGORIES=	devel meta-pkgs
MASTER_SITES=	# blank
DISTFILES=	# blank

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.redmine.org/
COMMENT=	Redmine themes meta package

DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-flatly-light-theme>=0.2.4:../../devel/ruby-redmine-flatly-light-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-gitmike-theme>=1.2.0:../../devel/ruby-redmine-gitmike-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-minimalflat-theme>=1.0.2:../../devel/ruby-redmine-minimalflat-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-minimalflat2-theme>=1.7.0:../../devel/ruby-redmine-minimalflat2-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-purplemine2-theme>=2.10.2:../../devel/ruby-redmine-purplemine2-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-red-andy-theme>=1.00:../../devel/ruby-redmine-red-andy-theme
DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-yh-theme>=1.6:../../devel/ruby-redmine-yh-theme

META_PACKAGE=		yes

RUBY_VERSIONS_ACCEPTED=	31

.include "../../devel/ruby-redmine/redmine.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
