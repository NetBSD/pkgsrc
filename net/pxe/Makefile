# $NetBSD: Makefile,v 1.16 2012/10/23 17:19:01 asau Exp $
#

DISTNAME=	pxe-1.4.2
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.kano.org.uk/projects/pxe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kano.org.uk/projects/pxe/
COMMENT=	Preboot eXecution Environment (PXE) daemon

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-log=${VARBASE}/log/pxe.log
CONFIGURE_ARGS+=	--with-config="${PKG_SYSCONFDIR}/pxe.conf"

EGDIR=		${PREFIX}/share/examples/pxe
CONF_FILES=	${EGDIR}/pxe.conf ${PKG_SYSCONFDIR}/pxe.conf

RCD_SCRIPTS=	pxe

BUILD_DEFS+=	VARBASE

.include "../../mk/bsd.pkg.mk"
