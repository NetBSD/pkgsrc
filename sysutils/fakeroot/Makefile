# $NetBSD: Makefile,v 1.6 2004/01/20 12:26:15 agc Exp $
#

DISTNAME=	fakeroot_0.5.8
PKGNAME=	fakeroot-0.5.8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fakeroot/}

MAINTAINER=	lonewolf@NetBSD.org
COMMENT=	Creates a fake root environment

WRKSRC=		${WRKDIR}/fakeroot-0.5.8
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
