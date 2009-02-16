# $NetBSD: Makefile,v 1.13 2009/02/16 18:49:58 joerg Exp $
#

DISTNAME=	sniff-2.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Program to sniff logins and passwords

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1 sbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LIBS+=		-lsocket -lnsl
MAKE_ENV+=	LIBS=${LIBS:M*:Q}
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
