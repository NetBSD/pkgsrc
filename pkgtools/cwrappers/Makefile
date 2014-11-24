# $NetBSD: Makefile,v 1.4 2014/11/24 00:31:03 joerg Exp $

PKGNAME=		cwrappers-20100308
CATEGORIES=		pkgtools sysutils

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		pkgsrc compiler wrappers
LICENSE=		modified-bsd

USE_BSD_MAKEFILE=	yes
USE_FEATURES=		nbcompat

INSTALLATION_DIRS=	libexec/cwrappers

.include "../../mk/bsd.prefs.mk"

USE_CWRAPPERS:=		no
CHECK_PERMS=		no

.if ${OPSYS} != "NetBSD" || !empty(MACHINE_PLATFORM:MNetBSD-[0-5].*)
MAKE_ENV+=	NEED_MI_VECTOR_HASH=1
.endif
.if !empty(MACHINE_PLATFORM:MDarwin-9.*) || !empty(MACHINE_PLATFORM:MDarwin-10.*)
MAKE_ENV+=	NEED_GETLINE=1
.endif

CFLAGS.FreeBSD+=	-D_WITH_GETLINE
CFLAGS.Linux+=	-D_GNU_SOURCE=1

do-extract:
	${CP} -R ${FILESDIR}/bin ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
