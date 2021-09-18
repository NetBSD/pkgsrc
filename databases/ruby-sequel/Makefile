# $NetBSD: Makefile,v 1.94 2021/09/18 13:53:29 taca Exp $

DISTNAME=	sequel-5.48.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sequel.jeremyevans.net/
COMMENT=	Model classes for the Sequel Database Toolkit
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

pre-build:
	${CHMOD} 0755 ${WRKSRC}/bin/sequel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
