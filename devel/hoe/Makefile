# $NetBSD: Makefile,v 1.69 2024/02/03 15:05:20 taca Exp $

DISTNAME=	hoe-4.2.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.zenspider.com/projects/hoe.html
COMMENT=	Rake extension to provide full project automation
LICENSE=	mit

USE_LANGUAGES=	# empty

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} == 31
DEPENDS+=	${RUBY_PKGPREFIX}-minitest>=1.0.0:../../devel/ruby-minitest
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
