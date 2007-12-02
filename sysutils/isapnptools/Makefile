# $NetBSD: Makefile,v 1.12 2007/12/02 11:39:34 wiz Exp $
#

DISTNAME=	isapnptools-1.26
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/hardware/} \
		ftp://ftp.demon.co.uk/pub/unix/linux/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.roestock.demon.co.uk/
COMMENT=	Manually query and configure isapnp devices

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-realtime
CONFIGURE_ARGS+=	--disable-pci

.include "../../mk/bsd.pkg.mk"
