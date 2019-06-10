# $NetBSD: Makefile,v 1.72 2019/06/10 16:02:39 taca Exp $

DISTNAME=	sequel-5.21.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sequel.jeremyevans.net/
COMMENT=	Model classes for the Sequel Database Toolkit
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

pre-build:
	${CHMOD} 0755 ${WRKSRC}/bin/sequel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
