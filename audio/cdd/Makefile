# $NetBSD: Makefile,v 1.11 2003/07/17 21:22:01 grant Exp $

DISTNAME=	cdd-1.0nb3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	thorpej@NetBSD.org
COMMENT=	Program for reading CD audio from SCSI/ATAPI CD-ROM drives

BUILD_DEPENDS+=	libscsi-1.6:../../devel/libscsi

.include "../../mk/bsd.prefs.mk"

.if defined(CDDCPPFLAGS)
MAKE_ENV+=      "CDDCPPFLAGS=${CDDCPPFLAGS}"
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdd ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/stripzeros ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
