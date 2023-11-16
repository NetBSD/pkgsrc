# $NetBSD: Makefile,v 1.20 2023/11/16 22:55:37 schmonz Exp $

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

DJB_CONFIG_PREFIX=	${PREFIX}/publicfile

SUBST_CLASSES+=		djberrno

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
