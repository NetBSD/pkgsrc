# $NetBSD: Makefile,v 1.13 2007/12/31 02:51:55 obache Exp $
#

DISTNAME=	isapnptools-1.27
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/hardware/} \
		ftp://ftp.demon.co.uk/pub/unix/linux/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.roestock.demon.co.uk/isapnptools/index.html
COMMENT=	Manually query and configure isapnp devices

ONLY_FOR_PLATFORM=	NetBSD-*-i386

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-realtime
CONFIGURE_ARGS+=	--disable-pci

.include "../../mk/bsd.pkg.mk"
