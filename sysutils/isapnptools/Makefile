# $NetBSD: Makefile,v 1.2 2002/07/23 14:33:24 agc Exp $
#

DISTNAME=	isapnptools-1.26
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/hardware/} \
		ftp://tsx-11.mit.edu/pub/linux/sources/sbin/ \
		ftp://ftp.demon.co.uk/pub/unix/linux/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.roestock.demon.co.uk
COMMENT=	manually query and configure isapnp devices

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-realtime --disable-pci

.include "../../mk/bsd.pkg.mk"
