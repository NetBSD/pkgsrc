# $NetBSD: Makefile,v 1.15 2008/03/02 06:10:31 jlam Exp $

DISTNAME=	cdd-1.0nb3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	thorpej@NetBSD.org
COMMENT=	Program for reading CD audio from SCSI/ATAPI CD-ROM drives

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if defined(CDDCPPFLAGS)
MAKE_ENV+=	CDDCPPFLAGS=${CDDCPPFLAGS:Q}
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdd ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/stripzeros ${DESTDIR}${PREFIX}/bin

.include "../../devel/libscsi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
