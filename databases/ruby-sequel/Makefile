# $NetBSD: Makefile,v 1.50 2017/01/13 15:30:04 taca Exp $

DISTNAME=	sequel-4.42.1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sequel.jeremyevans.net/
COMMENT=	Model classes for the Sequel Database Toolkit
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

pre-build:
	${CHMOD} 0755 ${WRKSRC}/bin/sequel

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
