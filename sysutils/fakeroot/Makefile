# $NetBSD: Makefile,v 1.1.1.1 2002/12/20 11:23:53 lonewolf Exp $
#

DISTNAME=	fakeroot_0.5.8
PKGNAME=	fakeroot-0.5.8
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/f/fakeroot/

MAINTAINER=	lonewolf@netbsd.org
COMMENT=	Creates a fake root environment

WRKSRC=		${WRKDIR}/fakeroot-0.5.8
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=${WRKSRC}/libtool
GNU_CONFIGURE=	YES

# XXX Kludge, configure bombs without this on my -current
CONFIG_SHELL=

.include "../../mk/bsd.pkg.mk"
