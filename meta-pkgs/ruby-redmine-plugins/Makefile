# $NetBSD: Makefile,v 1.17 2023/09/09 13:52:56 taca Exp $

DISTNAME=	redmine-plugins-1.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/redmine/redmine${RM_VER}/}
CATEGORIES=	devel meta-pkgs
MASTER_SITES=	# blank
DISTFILES=	# blank

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.redmine.org/
COMMENT=	Redmine plugins meta package

DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-code_review-[0-9]*:../../devel/ruby-redmine_code_review
DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-lightbox2-[0-9]*:../../devel/ruby-redmine_lightbox2
DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-theme_changer-[0-9]*:../../devel/ruby-redmine_theme_changer
DEPENDS+=	${RUBY_PKGPREFIX}-redmine${RM_VER}-work_time-[0-9]*:../../devel/ruby-redmine_work_time

META_PACKAGE=		yes
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.common ${.CURDIR}/MESSAGE

RUBY_VERSIONS_ACCEPTED=	31

.include "../../devel/ruby-redmine/redmine.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
