# $NetBSD: Makefile,v 1.8 2023/07/03 11:29:03 vins Exp $

DISTNAME=	got-portable-0.90
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
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin libexec
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
USE_TOOLS+=	bison
# compatibility macros and functions for Linux.
.  include "../../devel/libbsd/buildlink3.mk"
.endif

.if ${OPSYS} == "Darwin"
USE_TOOLS+=	bison
# define uuid library to use
.  include "../../devel/ossp-uuid/buildlink3.mk"
.else
.  include "../../devel/libuuid/buildlink3.mk"
.endif

# need libcrypto.so.1.1
BUILDLINK_API_DEPENDS.openssl+=   openssl>=1.1.1d
.include "../../security/openssl/buildlink3.mk"

# required for set_panel_userptr(3) and waddwstr(3).
.include "../../devel/ncursesw/buildlink3.mk"

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
