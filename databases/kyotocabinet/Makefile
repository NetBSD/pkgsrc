# $NetBSD: Makefile,v 1.7 2020/11/13 16:12:02 nia Exp $
#

DISTNAME=	kyotocabinet-1.2.77
CATEGORIES=	databases
MASTER_SITES=	https://fallabs.com/kyotocabinet/pkg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fallabs.com/kyotocabinet/
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

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
# using GCC atomic functions only available with i586 in kcthread.cc
.if !empty(CC_VERSION:Mgcc-*) && !empty(MACHINE_ARCH:Mi[34]86)
GNU_ARCH.i386=		i586
CFLAGS+=		-march=i586
.endif

.if ${MACHINE_ARCH} == "powerpc"
.include "../../devel/libatomic/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
