# $NetBSD: Makefile,v 1.2 2003/01/19 18:10:11 cjep Exp $

DISTNAME=	nail-10.4
CATEGORIES=	mail
MASTER_SITES=	http://omnibus.ruf.uni-freiburg.de/~gritter/archive/nail/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://omnibus.ruf.uni-freiburg.de/~gritter/
COMMENT=	BSD mail utility with MIME extensions

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rcfile=${PKG_SYSCONFDIR}/nail.rc

EGDIR=		${PREFIX}/share/examples/nail

CONF_FILES=     ${EGDIR}/nail.rc ${PKG_SYSCONFDIR}/nail.rc

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/nail ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/nail.1 ${PREFIX}/man/man1
		${INSTALL_DATA_DIR} ${EGDIR}
		${INSTALL_DATA} ${WRKSRC}/nail.rc ${EGDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
