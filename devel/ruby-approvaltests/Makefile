# $NetBSD: Makefile,v 1.2 2023/02/11 14:17:25 taca Exp $

DISTNAME=	approvals-0.0.26
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/approvals/approvaltests/}
CATEGORIES=	devel

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://approvaltests.com/
COMMENT=	Assertion/verification library to aid testing
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=1.0:../../devel/ruby-thor

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
