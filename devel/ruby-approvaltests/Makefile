# $NetBSD: Makefile,v 1.1 2021/06/07 19:55:27 schmonz Exp $

DISTNAME=	approvals-0.0.25
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/approvals/approvaltests/}
CATEGORIES=	devel

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://approvaltests.com/
COMMENT=	Assertion/verification library to aid testing
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-json>=2.0:../../textproc/ruby-json
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=1.0:../../devel/ruby-thor

RUBYGEM_OPTIONS+=	--format-executable

SUBST_CLASSES+=		jsondep
SUBST_STAGE.jsondep=	pre-configure
SUBST_FILES.jsondep=	${WRKDIR}/${DISTNAME}.gemspec
SUBST_SED.jsondep=	-e 's|, "ext/mkrf_conf.rb".freeze||'
SUBST_SED.jsondep+=	-e   's|"ext/mkrf_conf.rb".freeze||'

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
