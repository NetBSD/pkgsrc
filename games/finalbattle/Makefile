# $NetBSD: Makefile,v 1.2 1998/08/20 15:16:54 tsarna Exp $
#

DISTNAME=	finalbattle.0.0
PKGNAME=	finalbattle-0.0
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/finalbattle/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.sonic.net/~nbs/unix/x/finalbattle/

MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/final

USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
.if (${OBJECT_FMT} == "ELF")
RPATH=		-Wl,-rpath,${PREFIX}/lib
.endif
MAKE_ENV+=	RPATH=${RPATH}
