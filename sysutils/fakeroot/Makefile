# $NetBSD: Makefile,v 1.3 2003/03/29 12:42:27 jmmv Exp $
#

DISTNAME=	fakeroot_0.5.8
PKGNAME=	fakeroot-0.5.8
WRKSRC=		${WRKDIR}/fakeroot-0.5.8
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/f/fakeroot/

MAINTAINER=	lonewolf@netbsd.org
COMMENT=	Creates a fake root environment

USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
