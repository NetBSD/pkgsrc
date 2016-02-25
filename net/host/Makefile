# $NetBSD: Makefile,v 1.30 2016/02/25 16:20:51 jperkin Exp $

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

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--warn-common
BUILDLINK_TRANSFORM.Darwin+=	rm:-static
CPPFLAGS.Darwin+=		-DBIND_8_COMPAT

BUILDLINK_TRANSFORM.SunOS+=	rm:-static
LDFLAGS.SunOS+=			-lresolv -lsocket -lnsl

BUILDLINK_TRANSFORM.Linux+=	rm:-static
LDFLAGS.Linux+=			-lresolv

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CPPFLAGS+=	-DIRIX5
.endif

.include "../../mk/bsd.pkg.mk"
