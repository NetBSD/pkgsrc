# $NetBSD: Makefile,v 1.17 2016/02/26 09:41:06 jperkin Exp $
#

DISTNAME=	sniff-2.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Program to sniff logins and passwords

INSTALLATION_DIRS=	${PKGMANDIR}/man1 sbin

LIBS.SunOS+=		-lsocket -lnsl
MAKE_ENV.SunOS+=	LIBS=${LIBS:M*:Q}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
