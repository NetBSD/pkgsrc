# $NetBSD: Makefile,v 1.18 2023/12/23 09:12:15 zafer Exp $

DISTNAME=		i2ocfg-1.1
CATEGORIES=		sysutils
MASTER_SITES=		https://www.aydogan.net/distfiles/sysutils/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.hairylemon.org/~ad/software/i2ocfg/
COMMENT=		I2O configuration dialog gateway

ONLY_FOR_PLATFORM=	NetBSD-*-*

USE_BSD_MAKEFILE=	YES
USE_TOOLS+=		groff nroff
INSTALL_MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	libexec/cgi-bin ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

MANCOMPRESSED_IF_MANZ=	YES

.include "../../mk/bsd.pkg.mk"
