# $NetBSD: Makefile,v 1.3 2000/02/02 06:53:42 itojun Exp $

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
# "bindir" setting is very non-standard for GNU autoconf
CONFIGURE_ARGS+=--disable-asmopt --bindir=/bin

.include "../../mk/bsd.pkg.mk"
