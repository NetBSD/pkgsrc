# $NetBSD: Makefile,v 1.6 2006/03/06 23:02:07 peter Exp $

DISTNAME=	pfstat-1.7
PKGREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://www.benzedrine.cx/pfstat.html
COMMENT=	Utility to render graphical statistics for PF

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin man/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfstat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfstat.8 ${PREFIX}/man/man8

.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../security/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
