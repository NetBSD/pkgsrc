# $NetBSD: Makefile,v 1.3 2000/01/03 22:08:56 agc Exp $
#

DISTNAME=	user-19991231
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/

WRKSRC=		${WRKDIR}/user

ONLY_FOR_PLATFORM=	NetBSD-*-* # already in Solaris base system

.if exists(/usr/sbin/user)
IGNORE=		"is part of your NetBSD distribution"
.endif

NO_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
