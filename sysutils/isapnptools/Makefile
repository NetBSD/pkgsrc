# $NetBSD: Makefile,v 1.8 2005/05/22 20:08:33 jlam Exp $
#

DISTNAME=	isapnptools-1.26
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/hardware/} \
		ftp://tsx-11.mit.edu/pub/linux/sources/sbin/ \
		ftp://ftp.demon.co.uk/pub/unix/linux/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.roestock.demon.co.uk/
COMMENT=	Manually query and configure isapnp devices

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-realtime --disable-pci

.include "../../mk/bsd.pkg.mk"
