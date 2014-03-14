# $NetBSD: Makefile,v 1.7 2014/03/14 17:26:06 taca Exp $

DISTNAME=	configuration-1.3.4
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ahoward/configuration
COMMENT=	Library for loading Ruby configuration files

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
