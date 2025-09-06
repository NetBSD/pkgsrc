# $NetBSD: Makefile,v 1.1 2025/09/06 18:27:51 riastradh Exp $

DISTNAME=	nss_wrapper-1.1.16
CATEGORIES=	devel
MASTER_SITES=	https://ftp.samba.org/pub/cwrap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cwrap.org/nss_wrapper.html
COMMENT=	LD_PRELOAD wrapper for the user, group and hosts NSS API
LICENSE=	modified-bsd

USE_TOOLS+=	perl:run

REPLACE_PERL+=	nss_wrapper.pl

CMAKE_CONFIGURE_ARGS+=	-DUNIT_TESTING:BOOL=TRUE

BUILDLINK_DEPMETHOD.cmocka=	build # for automatic tests only

# All tests should pass on NetBSD 9/amd64.

TEST_TARGET=	test

.include "../../devel/cmake/build.mk"
.include "../../devel/cmocka/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
