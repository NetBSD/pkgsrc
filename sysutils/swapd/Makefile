# $NetBSD: Makefile,v 1.1.1.1 2004/10/30 05:06:14 xtraeme Exp $
#

DISTNAME=	swapd-1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rkeene.org/files/oss/swapd/source/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.rkeene.org/oss/swapd/
COMMENT=	Watches free memory and manages swap files

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-* Linux-*-*

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes

RCD_SCRIPTS=	swapd

EGDIR=		${PREFIX}/share/examples/swapd
CONF_FILES=	${EGDIR}/swapd.conf ${PKG_SYSCONFDIR}/swapd.conf

.include "../../devel/libstatgrab/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
