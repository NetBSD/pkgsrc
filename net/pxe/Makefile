# $NetBSD: Makefile,v 1.15 2007/12/22 12:08:58 obache Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
