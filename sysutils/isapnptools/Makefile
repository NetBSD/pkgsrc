# $NetBSD: Makefile,v 1.1.1.1 2002/07/23 12:07:45 agc Exp $
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

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-realtime --disable-pci

.include "../../mk/bsd.pkg.mk"
