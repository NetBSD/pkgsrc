# $NetBSD: Makefile,v 1.6 2012/10/23 17:18:12 asau Exp $

DISTNAME=	bsddip-1.02
CATEGORIES=	net
#
# the actual master site is almost out of reach for everybody
#MASTER_SITES=	ftp://sun.rz.tu-clausthal.de/pub/bsddip/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Dialup IP program

NOT_FOR_PLATFORM=	Interix-*-* # no sl(4) device

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin

NO_CONFIGURE=	yes
MANCOMPRESSED_IF_MANZ=	yes
MAKE_ENV+=	${BSD_MAKE_ENV}

post-extract:
	cp -f ${FILESDIR}/Makefile ${WRKSRC}/.

.include "../../mk/bsd.pkg.mk"
