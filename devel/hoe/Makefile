# $NetBSD: Makefile,v 1.62 2022/12/22 01:47:47 taca Exp $

DISTNAME=	hoe-4.0.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.zenspider.com/projects/hoe.html
COMMENT=	Rake extension to provide full project automation
LICENSE=	mit

# hoe implictly assumes minitest 5.16 and later is available.
DEPENDS+=	${RUBY_PKGPREFIX}-minitest>=5.16:../../devel/ruby-minitest

USE_LANGUAGES=	# empty

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
