# $NetBSD: Makefile,v 1.21 2025/05/22 04:51:28 schmonz Exp $

DISTNAME=		publicfile-0.52
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		https://cr.yp.to/publicfile/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/publicfile.html
COMMENT=		Secure read-only HTTP and FTP servers
LICENSE=		djb-nonlicense

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		{ucspi-tcp6-[0-9]*,ucspi-tcp-[0-9]*}:../../net/ucspi-tcp6

FORCE_C_STD=		c89

DJB_CONFIG_PREFIX=	${PREFIX}/${PKGBASE}
DJB_ERRNO_FIXUP=	error.h

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
