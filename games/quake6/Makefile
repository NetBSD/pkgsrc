# $NetBSD: Makefile,v 1.4 2000/02/11 03:58:14 hubertf Exp $

DISTNAME=	quake-v6-bsd-kame
PKGNAME=	quake6-0.0
CATEGORIES=	games
MASTER_SITES=	http://www.viagenie.qc.ca/quake/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	quake6-00-v6-20000202b.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.viagenie.qc.ca/en/ipv6-quake.shtml

DEPENDS=	quakedata-*:../../games/quakedata

WRKSRC=		${WRKDIR}/quakeforge

post-extract:
	(cd ${WRKSRC}; ${FIND} . -name \*.o -exec ${RM} {} \;)
	(cd ${WRKSRC}; ${RM} config.cache)

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
# This pkg does not regard USE_INET6, but works fine with IPv6
# "bindir" setting is very non-standard for GNU autoconf
CONFIGURE_ARGS+=--disable-asmopt --bindir=/bin

.include "../../mk/bsd.pkg.mk"
