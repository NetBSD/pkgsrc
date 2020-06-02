# $NetBSD: Makefile,v 1.26 2020/06/02 19:46:00 rillig Exp $

PKGNAME=		cwrappers-20180325
CATEGORIES=		pkgtools sysutils

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		pkgsrc compiler wrappers
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes
USE_BSD_MAKEFILE=	yes
USE_FEATURES=		nbcompat

INSTALLATION_DIRS=	libexec/cwrappers

.include "../../mk/bsd.prefs.mk"

CHECK_PERMS_SKIP=	*	# avoid dependency cycles with sysutils/checkperms
CHECK_PORTABILITY_SKIP=	*	# avoid dependency cycles with pkgtools/check-portability
PKGSRC_LOCKTYPE=	none	# avoid dependency cycles with pkgtool/shlock

.if ${OPSYS} != "NetBSD" || !empty(MACHINE_PLATFORM:MNetBSD-[0-5].*)
MAKE_ENV+=	NEED_MI_VECTOR_HASH=1
.endif

CFLAGS.FreeBSD+=	-D_WITH_GETLINE
CFLAGS.Linux+=		-D_GNU_SOURCE=1

do-extract:
	${CP} -R ${FILESDIR}/bin ${WRKSRC}
	${TOUCH} ${WRKSRC}/transform-gcc.c

.include "../../mk/bsd.pkg.mk"
