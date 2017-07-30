# $NetBSD: Makefile,v 1.8 2017/07/30 22:32:19 wiz Exp $

DISTNAME=	configuration-1.3.4
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ahoward/configuration
COMMENT=	Library for loading Ruby configuration files

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
