# $NetBSD: Makefile,v 1.1.1.1 2004/11/05 15:07:15 peter Exp $

DISTNAME=	pfstat-1.7
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://www.benzedrine.cx/pfstat.html
COMMENT=	Utility to render graphical statistics for PF

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfstat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfstat.8 ${PREFIX}/man/man8

.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../security/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
