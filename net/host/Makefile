# $NetBSD: Makefile,v 1.17 2007/10/16 23:49:01 tnn Exp $

DISTNAME=	host-20040812
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.weird.com/pub/local/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.weird.com/~woods/projects/host.html
COMMENT=	Powerful DNS query and testing tool

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
NO_CONFIGURE =	yes

MAKE_ENV+=	${BSD_MAKE_ENV}
MAKE_FILE=	Makefile.BSD
MAKE_FLAGS+=	__NetBSD__=1

USE_TOOLS+=	nroff

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CPPFLAGS+=	-DBIND_8_COMPAT
BUILDLINK_TRANSFORM+=	rm:-Wl,--warn-common
BUILDLINK_TRANSFORM+=	rm:-static
.endif
.if ${OPSYS} == "IRIX"
CPPFLAGS+=	-DIRIX5
.endif

.include "../../mk/bsd.pkg.mk"
