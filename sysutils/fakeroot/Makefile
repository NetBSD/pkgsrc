# $NetBSD: Makefile,v 1.4 2003/06/05 17:20:27 jmmv Exp $
#

DISTNAME=	fakeroot_0.5.8
PKGNAME=	fakeroot-0.5.8
WRKSRC=		${WRKDIR}/fakeroot-0.5.8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fakeroot/}

MAINTAINER=	lonewolf@netbsd.org
COMMENT=	Creates a fake root environment

USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
