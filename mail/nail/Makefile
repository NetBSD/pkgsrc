# $NetBSD: Makefile,v 1.10 2004/04/19 10:17:01 cjep Exp $

DISTNAME=	nail-10.7
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://nail.sourceforge.net/
COMMENT=	BSD mail utility with MIME extensions

USE_BUILDLINK3=	yes
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
