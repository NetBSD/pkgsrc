# $NetBSD: Makefile,v 1.2 2003/01/04 11:27:44 cjep Exp $
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

.include "../../mk/bsd.pkg.mk"
