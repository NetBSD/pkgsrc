# $NetBSD: Makefile,v 1.14 2004/04/19 14:07:36 markd Exp $
#

DISTNAME=	${PKGNAME_NOREV:S/-/_/}.src
PKGNAME=	malsync-2.1.1
PKGREVISION=			1
CATEGORIES=	comms
MASTER_SITES=	http://www.tomw.org/malsync/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.tomw.org/malsync/
COMMENT=	Utility to synchronize Palm Pilots to the AvantGo.com service

CONFLICTS+=	libmal-[0-9]*

WRKSRC=		${WRKDIR}/malsync
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
MAKE_ENV+=		PILOT_LINK_DIR=${BUILDLINK_PREFIX.pilot-link-libs}
CPPFLAGS+=		-D__unix__=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/malsync ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/malsync
.for doc in README_avantgo README_malsync
	${INSTALL_DATA} ${FILESDIR}/${doc} ${PREFIX}/share/doc/malsync
.endfor

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
