# $NetBSD: Makefile,v 1.7 2003/12/05 22:21:17 cjep Exp $

DISTNAME=	nail-10.6
CATEGORIES=	mail
MASTER_SITES=	http://omnibus.ruf.uni-freiburg.de/~gritter/archive/nail/

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
