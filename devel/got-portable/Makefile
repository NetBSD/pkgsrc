# $NetBSD: Makefile,v 1.15 2023/10/24 22:08:45 wiz Exp $

DISTNAME=	got-portable-0.93
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://gameoftrees.org/releases/portable/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://gameoftrees.org/portable.html
COMMENT=	Game of Trees version control system manipulating Git repo
LICENSE=	isc

CONFLICTS+=		got-[0-9]*

ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	Darwin-*-*
ONLY_FOR_PLATFORM+=	Linux-*-*
ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

USE_TOOLS+=	pkg-config yacc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "Darwin"
USE_TOOLS+=	bison
.endif

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin libexec
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.if ${OPSYS} == "Linux"
post-patch:
# let libmd include the correct header.
	${RM} -f ${WRKSRC}/compat/sha2.h
# compatibility macros and functions for Linux.
.  include "../../devel/libbsd/buildlink3.mk"
.endif

# need libcrypto.so.1.1
BUILDLINK_API_DEPENDS.openssl+=   openssl>=1.1.1d
.include "../../security/openssl/buildlink3.mk"

# required for set_panel_userptr(3) and waddwstr(3).
.include "../../devel/ncursesw/buildlink3.mk"

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
