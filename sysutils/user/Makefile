# $NetBSD: Makefile,v 1.4 2000/01/10 12:08:52 agc Exp $
#

DISTNAME=		user-19991231
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/user

ONLY_FOR_PLATFORM=	NetBSD-*-* # already in Solaris base system

.if exists(/usr/sbin/user)
IGNORE=			"is part of your NetBSD distribution"
.endif

LOCALBASE=		/usr
NO_CONFIGURE=		yes
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done
MANCOMPRESSED_IF_MANZ=	yes

MAKE_ENV+=		BINDIR=/usr/sbin MANDIR=/usr/share/man

.include "../../mk/bsd.pkg.mk"
