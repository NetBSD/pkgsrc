# $NetBSD: Makefile,v 1.6 2019/11/03 19:35:55 rillig Exp $

DISTNAME=	redmine-plugins-1.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel meta-pkgs
MASTER_SITES=	# blank
DISTFILES=	# blank

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.redmine.org/
COMMENT=	Redmine plugins meta package

DEPENDS+=	${RUBY_PKGPREFIX}-redmine_code_review-[0-9]*:../../devel/ruby-redmine_code_review
DEPENDS+=	${RUBY_PKGPREFIX}-redmine_jenkins-[0-9]*:../../devel/ruby-redmine_jenkins
DEPENDS+=	${RUBY_PKGPREFIX}-redmine_lightbox2-[0-9]*:../../devel/ruby-redmine_lightbox2
DEPENDS+=	${RUBY_PKGPREFIX}-redmine_startpage-[0-9]*:../../devel/ruby-redmine_startpage
DEPENDS+=	${RUBY_PKGPREFIX}-redmine_theme_changer-[0-9]*:../../devel/ruby-redmine_theme_changer
DEPENDS+=	${RUBY_PKGPREFIX}-redmine_work_time-[0-9]*:../../devel/ruby-redmine_work_time

META_PACKAGE=		yes
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.common ${.CURDIR}/MESSAGE
RUBY_VERSIONS_ACCEPTED=	22

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
