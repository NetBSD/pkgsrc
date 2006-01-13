# $NetBSD: Makefile,v 1.10 2006/01/13 18:26:04 wiz Exp $
#

DISTNAME=	fakeroot_1.5.6
PKGNAME=	fakeroot-1.5.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fakeroot/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Creates a fake root environment

BUILD_DEPENDS+=	po4a-[0-9]*:../../textproc/po4a

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
# 3 test failures in 1.5.6
TEST_TARGET=	check

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
