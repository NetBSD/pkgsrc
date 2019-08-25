# $NetBSD: Makefile,v 1.2 2019/08/25 16:10:08 tsutsui Exp $

DISTNAME=	twitter-text-simpleidn-3.0.0.0
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/shibafu528/twitter-text-simpleidn
COMMENT=	Forked version of Twitter-text gem without libIDN dependency
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-unf-[0-9]*:../../converters/ruby-unf
DEPENDS+=	${RUBY_PKGPREFIX}-simpleidn-[0-9]*:../../devel/ruby-simpleidn

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
