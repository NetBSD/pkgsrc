# $NetBSD: Makefile,v 1.2 2010/09/10 07:22:08 taca Exp $

DISTNAME=	configuration-1.1.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/ahoward/configuration
COMMENT=	Library for loading Ruby configuration files
LICENSE=	# unknown

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
