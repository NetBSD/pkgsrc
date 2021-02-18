# $NetBSD: Makefile,v 1.10 2021/02/18 18:02:46 nia Exp $
#

DISTNAME=	kyotocabinet-1.2.79
CATEGORIES=	databases
MASTER_SITES=	https://dbmx.net/kyotocabinet/pkg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dbmx.net/kyotocabinet/
COMMENT=	Straightforward implementation of DBM
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_GCC_RUNTIME=	yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=	kyotocabinet.pc.in

.include "options.mk"

TEST_TARGET=	check

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
