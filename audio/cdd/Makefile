# $NetBSD: Makefile,v 1.12 2005/04/05 10:56:44 wiz Exp $

DISTNAME=	cdd-1.0nb3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	thorpej@NetBSD.org
COMMENT=	Program for reading CD audio from SCSI/ATAPI CD-ROM drives

.include "../../mk/bsd.prefs.mk"

.if defined(CDDCPPFLAGS)
MAKE_ENV+=      "CDDCPPFLAGS=${CDDCPPFLAGS}"
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdd ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/stripzeros ${PREFIX}/bin

.include "../../devel/libscsi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
