# $NetBSD: Makefile,v 1.9 2004/04/25 03:09:56 snj Exp $
#

DISTNAME=	sniff-2.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Program to sniff logins and passwords

USE_BUILDLINK3=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LIBS+=		-lsocket -lnsl
MAKE_ENV+=	LIBS="${LIBS}"
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
