# $NetBSD: Makefile,v 1.16 2012/10/23 19:51:01 asau Exp $
#

DISTNAME=	fakeroot_1.5.10
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/f/fakeroot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Creates a fake root environment

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
# 3 test failures in 1.5.10
TEST_TARGET=	check

MAKE_ENV+=	COLUMNS=76

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
