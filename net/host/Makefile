# $NetBSD: Makefile,v 1.28 2013/07/21 12:28:32 shattered Exp $

DISTNAME=	host-20070128
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.planix.com/pub/Planix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.weird.com/~woods/projects/host.html
COMMENT=	Powerful DNS query and testing tool

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1
NO_CONFIGURE =	yes

CONFLICTS+=	bind-[0-9]*

USE_BSD_MAKEFILE=	yes
MAKE_FILE=	Makefile.BSD
MAKE_FLAGS+=	__NetBSD__=1

USE_TOOLS+=	nroff

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CPPFLAGS+=	-DBIND_8_COMPAT
BUILDLINK_TRANSFORM+=	rm:-Wl,--warn-common
BUILDLINK_TRANSFORM+=	rm:-static
.endif
.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lresolv -lsocket -lnsl
BUILDLINK_TRANSFORM+=	rm:-Wl,--warn-common
BUILDLINK_TRANSFORM+=	rm:-static
.endif
.if ${OPSYS} == "Linux"
LDFLAGS+=		-lresolv
BUILDLINK_TRANSFORM+=	rm:-static
.endif
.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CPPFLAGS+=	-DIRIX5
.endif

.include "../../mk/bsd.pkg.mk"
