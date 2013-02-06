# $NetBSD: Makefile,v 1.16 2013/02/06 19:31:05 jperkin Exp $
#

DISTNAME=	sniff-2.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Program to sniff logins and passwords

INSTALLATION_DIRS=	${PKGMANDIR}/man1 sbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LIBS+=		-lsocket -lnsl
MAKE_ENV+=	LIBS=${LIBS:M*:Q}
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
