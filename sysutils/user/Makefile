# $NetBSD: Makefile,v 1.1.1.1 1999/12/16 16:28:31 agc Exp $
#

DISTNAME=	user
PKGNAME=	user-19991216
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/src/usr.sbin/
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/

WRKSRC=		${WRKDIR}/pub/NetBSD/NetBSD-current/src/usr.sbin/user

ONLY_FOR_PLATFORM=	NetBSD-*-* # already in Solaris base system

.if exists(/usr/sbin/user)
IGNORE=		"is part of your NetBSD distribution"
.endif

NO_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
