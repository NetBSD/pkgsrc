# $NetBSD: Makefile,v 1.8 2004/04/06 19:00:39 cjep Exp $

DISTNAME=	nail-10.7
CATEGORIES=	mail
MASTER_SITES=	http://nail.berlios.de/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://omnibus.ruf.uni-freiburg.de/~gritter/
COMMENT=	BSD mail utility with MIME extensions

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rcfile=${PKG_SYSCONFDIR}/nail.rc

EGDIR=		${PREFIX}/share/examples/nail

CONF_FILES=     ${EGDIR}/nail.rc ${PKG_SYSCONFDIR}/nail.rc

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/nail ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/nail.1 ${PREFIX}/man/man1
		${INSTALL_DATA_DIR} ${EGDIR}
		${INSTALL_DATA} ${WRKSRC}/nail.rc ${EGDIR}

.include "../../mk/bsd.pkg.mk"
