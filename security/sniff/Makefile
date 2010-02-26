# $NetBSD: Makefile,v 1.14 2010/02/26 10:28:34 wiz Exp $
#

DISTNAME=	sniff-2.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
