# $NetBSD: Makefile,v 1.5 2000/01/13 17:31:14 hubertf Exp $
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

NO_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

MAKE_ENV+=		BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man \
			FILESDIR=${PREFIX}/share/examples/usermgmt

pre-install:
			${INSTALL_DATA_DIR} ${PREFIX}/share/examples/usermgmt

.include "../../mk/bsd.pkg.mk"
