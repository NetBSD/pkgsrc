# $NetBSD: Makefile,v 1.12 2006/03/04 21:29:18 jlam Exp $

DISTNAME=	newmkdep-1.0
CATEGORIES=	devel
MASTER_SITES=	http://core.de/~tron/

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
