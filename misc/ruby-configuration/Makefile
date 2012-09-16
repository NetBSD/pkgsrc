# $NetBSD: Makefile,v 1.6 2012/09/16 06:45:23 taca Exp $

DISTNAME=	configuration-1.3.2
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ahoward/configuration
COMMENT=	Library for loading Ruby configuration files

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
