# $NetBSD: Makefile,v 1.58 2017/12/09 02:26:16 taca Exp $

DISTNAME=	sequel-5.3.0
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
