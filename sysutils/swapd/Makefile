# $NetBSD: Makefile,v 1.15 2009/05/19 08:59:35 wiz Exp $
#

DISTNAME=	swapd-1.0.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rkeene.org/files/oss/swapd/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rkeene.org/oss/swapd/
COMMENT=	Swap daemon for POSIX-compliant operating systems
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-* Linux-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

RCD_SCRIPTS=	swapd

EGDIR=		${PREFIX}/share/examples/swapd
CONF_FILES=	${EGDIR}/swapd.conf ${PKG_SYSCONFDIR}/swapd.conf

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../devel/libstatgrab/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
