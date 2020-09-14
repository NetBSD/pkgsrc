# $NetBSD: Makefile,v 1.4 2020/09/14 16:31:12 taca Exp $

DISTNAME=	license-acceptance-2.1.2
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/license-acceptance
COMMENT=	Chef End User License Agreement Acceptance
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.7<1:../../devel/ruby-pastel
DEPENDS+=	${RUBY_PKGPREFIX}-tomlrb>=1.2<2:../../devel/ruby-tomlrb
DEPENDS+=	${RUBY_PKGPREFIX}-tty-box>=0.6<1:../../devel/ruby-tty-box
DEPENDS+=	${RUBY_PKGPREFIX}-tty-prompt>=0.20<1:../../devel/ruby-tty-prompt

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
