# $NetBSD: Makefile,v 1.1.1.1 2000/06/15 14:04:46 rh Exp $
#

DISTNAME=	${PKGNAME:S/-/_/}.src
PKGNAME=	malsync-2.0.4
WRKSRC=		${WRKDIR}/malsync/mal/client/unix
CATEGORIES=	comms
MASTER_SITES=	http://www.tomw.org/malsync/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.tomw.org/malsync/

DEPENDS+=	pilot-link>=0.9.3:../../comms/pilot-link

NO_CONFIGURE=	YES
USE_GMAKE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/malsync ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/malsync
.for doc in README_avantgo README_malsync
	${INSTALL_DATA} ${FILESDIR}/${doc} ${PREFIX}/share/doc/malsync
.endfor

.include "../../mk/bsd.pkg.mk"
