# $NetBSD: Makefile,v 1.6 2002/10/05 03:43:42 wiz Exp $
#

DISTNAME=	${PKGNAME_NOREV:S/-/_/}.src
PKGNAME=	malsync-2.0.5
PKGREVISION=	1
WRKSRC=		${WRKDIR}/malsync/mal/client/unix
CATEGORIES=	comms
MASTER_SITES=	http://www.tomw.org/malsync/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.tomw.org/malsync/
COMMENT=	utility to synchronize Palm Pilots to the AvantGo.com service

USE_BUILDLINK2=		YES
USE_GMAKE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/malsync ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/malsync
.for doc in README_avantgo README_malsync
	${INSTALL_DATA} ${FILESDIR}/${doc} ${PREFIX}/share/doc/malsync
.endfor

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
