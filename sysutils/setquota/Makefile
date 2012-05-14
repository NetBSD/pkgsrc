# $NetBSD: Makefile,v 1.13.26.1 2012/05/14 12:28:56 tron Exp $
#

DISTNAME=	setquota-0.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.jurai.net/users/winter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# unknown
COMMENT=	Command line quota tools

PKG_DESTDIR_SUPPORT=	user-destdir

# BSD oriented, haven't checked on other environment now
ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-*

# not portable to netbsd-6 and up quota system
# (would be easier to rewrite it than to patch it, if there's any interest
# bug dholland)
NOT_FOR_PLATFORM=	NetBSD-[6-9]*-*

WRKSRC=		${WRKDIR}/setquota/

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin
USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.pkg.mk"
