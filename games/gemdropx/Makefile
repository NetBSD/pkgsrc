# $NetBSD: Makefile,v 1.1 1998/07/25 21:22:38 frueauf Exp $
#

DISTNAME=	gemdropx
PKGNAME=	gemdropx-0.3
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/gemdropx/

MAINTAINER=	root@garbled.net

MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/gemdropx

USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
.if (${OBJECT_FMT} == "ELF")
RPATH=		-Wl,-rpath,${PREFIX}/lib
.endif
MAKE_ENV+=	RPATH=${RPATH}
