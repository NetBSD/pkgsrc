# $NetBSD: Makefile,v 1.9 2007/05/18 10:03:32 peter Exp $

DISTNAME=	pfstat-1.7
PKGREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.benzedrine.cx/pfstat.html
COMMENT=	Utility to render graphical statistics for PF

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfstat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfstat.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../security/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
