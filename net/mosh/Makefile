# $NetBSD: Makefile,v 1.43 2024/06/08 17:52:24 agc Exp $

DISTNAME=	mosh-1.4.0
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	https://mosh.org/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://mosh.org/
COMMENT=	Remote terminal application which allows roaming
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run pkg-config
USE_LANGUAGES+=		c c++
USE_GCC_RUNTIME=	yes

FORCE_CXX_STD=	c++14

REPLACE_PERL+=	scripts/mosh.pl
REPLACE_PERL+=	src/tests/genbase64.pl
REPLACE_PERL+=	src/tests/hold-stdin
REPLACE_PERL+=	src/tests/print-exitstatus

TEST_TARGET=	check

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=    zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
