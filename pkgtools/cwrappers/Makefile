# $NetBSD: Makefile,v 1.16 2016/09/15 17:08:14 joerg Exp $

PKGNAME=		cwrappers-20160908
CATEGORIES=		pkgtools sysutils

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		pkgsrc compiler wrappers
LICENSE=		modified-bsd

USE_BSD_MAKEFILE=	yes
USE_FEATURES=		nbcompat

INSTALLATION_DIRS=	libexec/cwrappers

.include "../../mk/bsd.prefs.mk"

CHECK_PERMS=		no

.if ${OPSYS} != "NetBSD" || !empty(MACHINE_PLATFORM:MNetBSD-[0-5].*)
MAKE_ENV+=	NEED_MI_VECTOR_HASH=1
.endif

CFLAGS.FreeBSD+=	-D_WITH_GETLINE
CFLAGS.Linux+=		-D_GNU_SOURCE=1

do-extract:
	${CP} -R ${FILESDIR}/bin ${WRKSRC}
	${TOUCH} ${WRKSRC}/transform-gcc.c

.include "../../mk/bsd.pkg.mk"
