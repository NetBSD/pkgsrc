# $NetBSD: Makefile,v 1.4 1998/08/23 20:45:01 frueauf Exp $

DISTNAME=	cdd-1.0myc2
PKGNAME=	cdd-1.0myc2
WRKSRC=		${WRKDIR}/cdd
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	thorpej@netbsd.org

DEPENDS+=	libscsi-1.6:../../devel/libscsi

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdd ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/stripzeros ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
