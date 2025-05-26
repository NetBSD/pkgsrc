# $NetBSD: Makefile,v 1.3 2025/05/26 15:23:07 taca Exp $

DISTNAME=	approvals-0.1.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/approvals/approvaltests/}
CATEGORIES=	devel

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://approvaltests.com/
COMMENT=	Assertion/verification library to aid testing
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=1.0<2:../../devel/ruby-thor

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
