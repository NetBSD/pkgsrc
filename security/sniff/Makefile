# $NetBSD: Makefile,v 1.12 2008/04/07 18:04:40 joerg Exp $
#

DISTNAME=	sniff-2.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Program to sniff logins and passwords

INSTALLATION_DIRS=	sbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LIBS+=		-lsocket -lnsl
MAKE_ENV+=	LIBS=${LIBS:M*:Q}
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
