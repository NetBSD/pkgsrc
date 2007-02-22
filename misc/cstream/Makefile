# $NetBSD: Makefile,v 1.6 2007/02/22 19:26:48 wiz Exp $

DISTNAME=	cstream-2.2
CATEGORIES=	misc
MASTER_SITES=	http://www.cons.org/cracauer/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cons.org/cracauer/
COMMENT=	General-purpose stream-handling tool with bandwidth limiting

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

.include "../../mk/bsd.pkg.mk"
