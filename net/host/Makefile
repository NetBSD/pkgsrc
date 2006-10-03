# $NetBSD: Makefile,v 1.15 2006/10/03 14:25:55 schwarz Exp $

DISTNAME=	host-20040812
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.weird.com/pub/local/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.weird.com/~woods/projects/host.html
COMMENT=	Powerful DNS query and testing tool

INSTALLATION_DIRS=	bin man/man1
NO_CONFIGURE =	yes

MAKE_FILE=	Makefile.BSD

MAKE_FLAGS+=	__NetBSD__=1

USE_TOOLS+=	nroff

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CPPFLAGS+=	-DBIND_8_COMPAT
BUILDLINK_TRANSFORM+=	rm:-Wl,--warn-common
BUILDLINK_TRANSFORM+=	rm:-static
.endif
.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=	-DIRIX5
.endif

.include "../../mk/bsd.pkg.mk"
