# $NetBSD: Makefile,v 1.5 2003/07/30 18:09:26 jmmv Exp $
#

DISTNAME=	pxe-1.2
PKGREVISION=	1
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.kano.org.uk/projects/pxe/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kano.org.uk/projects/pxe/
COMMENT=	Preboot eXecution Environment (PXE) daemon

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=--with-log=/var/log/pxe.log
CONFIGURE_ARGS+=--with-config="${PKG_SYSCONFDIR}/pxe.conf"

EGDIR=		${PREFIX}/share/examples/pxe
CONF_FILES=	${EGDIR}/pxe.conf ${PKG_SYSCONFDIR}/pxe.conf

RCD_SCRIPTS=	pxe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pxe ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/pxe.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
