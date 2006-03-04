# $NetBSD: Makefile,v 1.12 2006/03/04 21:30:40 jlam Exp $
#

DISTNAME=	fakeroot_1.5.6
PKGNAME=	fakeroot-1.5.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fakeroot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Creates a fake root environment

BUILD_DEPENDS+=	po4a-[0-9]*:../../textproc/po4a

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
# 3 test failures in 1.5.6
TEST_TARGET=	check

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
