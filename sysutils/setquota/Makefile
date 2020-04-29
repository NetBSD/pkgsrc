# $NetBSD: Makefile,v 1.16 2020/04/29 20:20:49 maya Exp $
#

DISTNAME=	setquota-0.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.jurai.net/users/winter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# unknown
COMMENT=	Command line quota tools

# BSD oriented, haven't checked on other environment now
# not portable to netbsd-6 and up quota system
# (would be easier to rewrite it than to patch it, if there's any interest
# bug dholland)
ONLY_FOR_PLATFORM=	DragonFly-*-*

WRKSRC=		${WRKDIR}/setquota/

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin
USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.pkg.mk"
