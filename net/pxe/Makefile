# $NetBSD: Makefile,v 1.8 2004/04/25 07:36:39 snj Exp $
#

DISTNAME=	pxe-1.4
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.kano.org.uk/projects/pxe/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kano.org.uk/projects/pxe/
COMMENT=	Preboot eXecution Environment (PXE) daemon

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_GCC_SHLIB=	YES

CONFIGURE_ARGS+=	--with-log=/var/log/pxe.log
CONFIGURE_ARGS+=	--with-config="${PKG_SYSCONFDIR}/pxe.conf"

EGDIR=		${PREFIX}/share/examples/pxe
CONF_FILES=	${EGDIR}/pxe.conf ${PKG_SYSCONFDIR}/pxe.conf

RCD_SCRIPTS=	pxe

.include "../../mk/bsd.pkg.mk"
