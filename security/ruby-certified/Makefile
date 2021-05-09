# $NetBSD: Makefile,v 1.1 2021/05/09 04:40:49 taca Exp $

DISTNAME=	certified-1.0.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stevegraham/certified
COMMENT=	Verify SSL certificates and provides certificate bundle
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
