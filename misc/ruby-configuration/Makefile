# $NetBSD: Makefile,v 1.5 2011/08/12 16:57:55 taca Exp $

DISTNAME=	configuration-1.3.1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ahoward/configuration
COMMENT=	Library for loading Ruby configuration files

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
