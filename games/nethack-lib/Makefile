# $NetBSD: Makefile,v 1.14 2003/07/21 16:49:57 martti Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-lib-${NETHACK_VERSION}

COMMENT=		Data files for Nethack

USE_BUILDLINK2=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh
ALL_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat

.include "../../mk/bsd.pkg.mk"
