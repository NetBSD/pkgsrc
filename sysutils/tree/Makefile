# $NetBSD: Makefile,v 1.10 2013/08/15 12:40:06 richard Exp $
#

DISTNAME=	tree-1.6.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://mama.indstate.edu/linux/tree/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mama.indstate.edu/users/ice/tree/
COMMENT=	Print a text or HTML tree diagram of a directory structure
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

CFLAGS+=	-Wall -fomit-frame-pointer
CFLAGS.linux+=	-DLINUX -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64

MAKE_FLAGS+=		prefix=${PREFIX:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		MANSUBDIR=${PKGMANDIR:Q}
MAKE_FLAGS+=		INSTALL_PROGRAM_DIR=${INSTALL_PROGRAM_DIR:Q}
MAKE_FLAGS+=		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=		INSTALL_MAN_DIR=${INSTALL_MAN_DIR:Q}
MAKE_FLAGS+=		INSTALL_MAN=${INSTALL_MAN:Q}

.include "../../mk/bsd.pkg.mk"
