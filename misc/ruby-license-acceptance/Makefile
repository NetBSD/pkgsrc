# $NetBSD: Makefile,v 1.2 2020/03/24 17:58:03 taca Exp $

DISTNAME=	license-acceptance-1.0.18
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/license-acceptance
COMMENT=	Chef End User License Agreement Acceptance
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.7<1:../../devel/ruby-pastel
DEPENDS+=	${RUBY_PKGPREFIX}-tomlrb>=1.2<2:../../devel/ruby-tomlrb
DEPENDS+=	${RUBY_PKGPREFIX}-tty-box>=0.3<1:../../devel/ruby-tty-box
DEPENDS+=	${RUBY_PKGPREFIX}-tty-prompt>=0.18<1:../../devel/ruby-tty-prompt

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
