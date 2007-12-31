# $NetBSD: Makefile,v 1.13 2007/12/31 02:07:09 obache Exp $

DISTNAME=		i2ocfg-1.1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.hairylemon.org/~ad/software/download/i2ocfg/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hairylemon.org/~ad/software/i2ocfg/
COMMENT=		I2O configuration dialog gateway

ONLY_FOR_PLATFORM=	NetBSD-1.5[J-Z]-* NetBSD-1.6*-* NetBSD-[2-9]*-*

USE_BSD_MAKEFILE=	YES
INSTALL_MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	libexec/cgi-bin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

MANCOMPRESSED_IF_MANZ=	YES

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
