# $NetBSD: Makefile,v 1.11 2014/02/09 16:48:42 wiedi Exp $
#

DISTNAME=	error-0.0
CATEGORIES=	devel
MASTER_SITES=	# ftp://ftp.gw.com/pub/people/christos/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Insert compiler errors in source files as comments

USE_FEATURES+=		cdefs
USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		nroff
INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
