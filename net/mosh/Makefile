# $NetBSD: Makefile,v 1.23 2019/08/11 13:22:11 wiz Exp $

DISTNAME=	mosh-1.3.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://mosh.mit.edu/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://mosh.mit.edu/
COMMENT=	Remote terminal application which allows roaming
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run pkg-config
USE_LANGUAGES+=	c c++11
USE_GCC_RUNTIME=yes

REPLACE_PERL+=	scripts/mosh.pl
REPLACE_PERL+=	src/tests/genbase64.pl
REPLACE_PERL+=	src/tests/hold-stdin
REPLACE_PERL+=	src/tests/print-exitstatus

TEST_TARGET=	check

.include "../../devel/protobuf/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=    zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
