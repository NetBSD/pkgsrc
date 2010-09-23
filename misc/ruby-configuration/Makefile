# $NetBSD: Makefile,v 1.3 2010/09/23 09:22:14 taca Exp $

DISTNAME=	configuration-1.1.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ahoward/configuration
COMMENT=	Library for loading Ruby configuration files

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
