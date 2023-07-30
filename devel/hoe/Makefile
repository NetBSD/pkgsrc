# $NetBSD: Makefile,v 1.66 2023/07/30 03:45:01 taca Exp $

DISTNAME=	hoe-4.0.5
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.zenspider.com/projects/hoe.html
COMMENT=	Rake extension to provide full project automation
LICENSE=	mit

# hoe implictly assumes minitest 5.16 and all Ruby contains as bundled gem
#DEPENDS+=	${RUBY_PKGPREFIX}-minitest>=5.16:../../devel/ruby-minitest

USE_LANGUAGES=	# empty

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
