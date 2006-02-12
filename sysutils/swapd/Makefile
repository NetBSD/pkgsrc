# $NetBSD: Makefile,v 1.12 2006/02/12 15:24:15 xtraeme Exp $
#

DISTNAME=	swapd-1.0.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rkeene.org/files/oss/swapd/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.rkeene.org/oss/swapd/
COMMENT=	Swap daemon for POSIX-compliant operating systems

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-* Linux-*-*

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

RCD_SCRIPTS=	swapd

EGDIR=		${PREFIX}/share/examples/swapd
CONF_FILES=	${EGDIR}/swapd.conf ${PKG_SYSCONFDIR}/swapd.conf

.include "../../devel/libstatgrab/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
