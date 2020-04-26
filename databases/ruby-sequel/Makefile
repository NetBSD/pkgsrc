# $NetBSD: Makefile,v 1.81 2020/04/26 08:40:46 taca Exp $

DISTNAME=	sequel-5.31.0
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
