#	$NetBSD: Makefile,v 1.3 1998/07/24 09:13:12 frueauf Exp $

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
