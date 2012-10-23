# $NetBSD: Makefile,v 1.8 2012/10/23 19:51:27 asau Exp $
#

DISTNAME=	tree-1.5.1.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://mama.indstate.edu/linux/tree/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mama.indstate.edu/users/ice/tree/
COMMENT=	Print a text or HTML tree diagram of a directory structure
LICENSE=	gnu-gpl-v2

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		MANSUBDIR=${PKGMANDIR:Q}
MAKE_FLAGS+=		INSTALL_PROGRAM_DIR=${INSTALL_PROGRAM_DIR:Q}
MAKE_FLAGS+=		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=		INSTALL_MAN_DIR=${INSTALL_MAN_DIR:Q}
MAKE_FLAGS+=		INSTALL_MAN=${INSTALL_MAN:Q}

.include "../../mk/bsd.pkg.mk"
