# $NetBSD: Makefile,v 1.2 1999/12/17 10:48:25 agc Exp $
#

DISTNAME=	user-19991216
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
