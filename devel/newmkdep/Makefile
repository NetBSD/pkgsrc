# $NetBSD: Makefile,v 1.13 2006/08/24 10:13:03 tron Exp $

DISTNAME=	newmkdep-1.0
CATEGORIES=	devel
MASTER_SITES=	http://scheler.de/~matthias/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Faster replacement for *BSD's "mkdep"

WRKSRC=		${WRKDIR}/newmkdep
NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-I/usr/include -I${ZOULARISBASE}/include
LDFLAGS+=	-L${ZOULARISBASE}/lib -lbsdcompat
.endif

.include "../../mk/bsd.pkg.mk"
